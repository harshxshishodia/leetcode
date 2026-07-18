#!/usr/bin/env python3
"""Validate the source LeetCode content tree without modifying it."""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import unquote, urlparse


PROBLEM_DIRECTORY = re.compile(r"^(?P<number>[1-9]\d*)\.\s+(?P<name>.+)$")
RANGE_DIRECTORY = re.compile(r"^\d+-\d+$")
HTML_IMAGE = re.compile(r"<img\b[^>]*\bsrc\s*=\s*['\"](?P<target>[^'\"]+)['\"]", re.IGNORECASE)
IGNORED_DIRECTORIES = {
    ".git",
    ".github",
    ".idea",
    ".vscode",
    "__pycache__",
    "build",
    "dist",
    "generated-mobile-content",
    "node_modules",
}


@dataclass(frozen=True)
class Problem:
    number: int
    name: str
    directory: Path
    readme: Path


class Validation:
    def __init__(self, root: Path) -> None:
        self.root = root.resolve()
        self.errors: list[str] = []
        self.problems: list[Problem] = []

    def error(self, path: Path, reason: str) -> None:
        try:
            display = path.resolve(strict=False).relative_to(self.root).as_posix()
        except ValueError:
            display = str(path)
        self.errors.append(f"{display}: {reason}")

    def run(self) -> list[Problem]:
        if not self.root.is_dir():
            self.error(self.root, "content root does not exist or is not a directory")
            return []
        self._validate_paths()
        self._discover_problems()
        self._validate_problem_readmes()
        self._validate_category_links()
        return sorted(self.problems, key=lambda problem: problem.number)

    def _iter_source_files(self):
        for path in self.root.rglob("*"):
            if any(part in IGNORED_DIRECTORIES for part in path.relative_to(self.root).parts):
                continue
            if path.is_file():
                yield path

    def _validate_paths(self) -> None:
        case_paths: dict[str, Path] = {}
        exact_paths: set[str] = set()
        for path in self._iter_source_files():
            relative = path.relative_to(self.root).as_posix()
            if relative in exact_paths:
                self.error(path, "duplicate path")
            exact_paths.add(relative)
            case_key = relative.casefold()
            previous = case_paths.get(case_key)
            if previous is not None and previous != path:
                self.error(path, f"case-sensitive path conflict with {previous.relative_to(self.root).as_posix()}")
            else:
                case_paths[case_key] = path
            if path.is_symlink():
                try:
                    path.resolve(strict=True).relative_to(self.root)
                except (OSError, ValueError):
                    self.error(path, "symbolic link resolves outside the content root or cannot be read")
            try:
                with path.open("rb") as stream:
                    stream.read(1)
            except OSError as exc:
                self.error(path, f"file cannot be read: {exc}")

    def _discover_problems(self) -> None:
        seen: dict[int, Path] = {}
        top_ranges = [path for path in self.root.iterdir() if path.is_dir() and RANGE_DIRECTORY.fullmatch(path.name)]
        if not top_ranges:
            self.error(self.root, "no numbered content ranges such as 1-1000 were found")
            return
        for top_range in sorted(top_ranges):
            for sub_range in sorted(path for path in top_range.iterdir() if path.is_dir()):
                if not RANGE_DIRECTORY.fullmatch(sub_range.name):
                    continue
                for directory in sorted(path for path in sub_range.iterdir() if path.is_dir()):
                    match = PROBLEM_DIRECTORY.fullmatch(directory.name)
                    if match is None:
                        continue
                    number = int(match.group("number"))
                    readme = directory / "README.md"
                    previous = seen.get(number)
                    if previous is not None:
                        self.error(directory, f"duplicate problem ID {number}; first found at {previous.relative_to(self.root)}")
                    else:
                        seen[number] = directory
                    if not readme.is_file():
                        self.error(directory, "missing required README.md")
                        continue
                    self.problems.append(Problem(number, match.group("name").strip(), directory, readme))

    def _read_utf8(self, path: Path) -> str | None:
        try:
            data = path.read_bytes()
        except OSError as exc:
            self.error(path, f"file cannot be read: {exc}")
            return None
        if not data:
            self.error(path, "required file is empty")
            return None
        try:
            return data.decode("utf-8")
        except UnicodeDecodeError as exc:
            self.error(path, f"unsupported encoding; expected UTF-8: {exc}")
            return None

    def _validate_problem_readmes(self) -> None:
        for problem in self.problems:
            text = self._read_utf8(problem.readme)
            if text is None:
                continue
            heading = re.search(r"^#\s+(\d+)\.\s+(.+?)\s*$", text, re.MULTILINE)
            if heading is None:
                self.error(problem.readme, "missing '# <number>. <name>' heading")
            elif int(heading.group(1)) != problem.number:
                self.error(problem.readme, f"heading problem ID {heading.group(1)} does not match directory ID {problem.number}")
            if not re.search(r"^\*\*Difficulty:\*\*\s*\S+", text, re.MULTILINE | re.IGNORECASE):
                self.error(problem.readme, "missing Difficulty metadata")
            self._validate_references(problem.readme, text, images_only=True)

    def _validate_category_links(self) -> None:
        category_root = self.root / "category"
        if not category_root.exists():
            return
        for category in sorted(category_root.glob("*.md")):
            text = self._read_utf8(category)
            if text is not None:
                self._validate_references(category, text, images_only=False)

    def _validate_references(self, source: Path, text: str, images_only: bool) -> None:
        references: list[tuple[str, bool]] = []
        for target, is_image in markdown_links(text):
            if not images_only or is_image:
                references.append((target, is_image))
        references.extend((match.group("target"), True) for match in HTML_IMAGE.finditer(text))
        seen: set[str] = set()
        for raw_target, is_image in references:
            target = raw_target.strip()
            if not target or target.startswith("#"):
                continue
            parsed = urlparse(target)
            if parsed.scheme.lower() in {"http", "https", "data"} or target.startswith("//"):
                continue
            if parsed.scheme:
                self.error(source, f"unsupported reference scheme in {target!r}")
                continue
            decoded = unquote(parsed.path).replace("\\", "/")
            if not decoded:
                continue
            resolved = (source.parent / decoded).resolve(strict=False)
            try:
                resolved.relative_to(self.root)
            except ValueError:
                self.error(source, f"unsafe relative reference escapes content root: {target}")
                continue
            key = str(resolved).casefold()
            if key in seen:
                continue
            seen.add(key)
            if not resolved.is_file():
                kind = "image" if is_image else "file"
                self.error(source, f"missing referenced {kind}: {target}")


def markdown_links(text: str):
    """Yield Markdown destinations while preserving balanced parentheses in paths."""
    cursor = 0
    while True:
        marker = text.find("](", cursor)
        if marker < 0:
            return
        opening = text.rfind("[", cursor, marker)
        is_image = opening > 0 and text[opening - 1] == "!"
        position = marker + 2
        if position >= len(text):
            return

        if text[position] == "<":
            end = text.find(">", position + 1)
            if end < 0:
                cursor = position + 1
                continue
            target = text[position + 1:end]
            closing = text.find(")", end + 1)
        else:
            start = position
            depth = 0
            escaped = False
            closing = -1
            while position < len(text):
                character = text[position]
                if escaped:
                    escaped = False
                elif character == "\\":
                    escaped = True
                elif character == "(":
                    depth += 1
                elif character == ")":
                    if depth == 0:
                        closing = position
                        break
                    depth -= 1
                position += 1
            target = text[start:closing].strip() if closing >= 0 else ""

        if closing < 0:
            cursor = marker + 2
            continue
        if target:
            yield target.strip("<>"), is_image
        cursor = closing + 1


def validate(root: Path) -> tuple[list[Problem], list[str]]:
    validation = Validation(root)
    problems = validation.run()
    return problems, validation.errors


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--content-root", type=Path, default=Path.cwd())
    args = parser.parse_args()
    problems, errors = validate(args.content_root)
    if errors:
        print(f"Content validation failed with {len(errors)} error(s):", file=sys.stderr)
        for error in errors:
            print(f"  - {error}", file=sys.stderr)
        return 1
    print(f"Content validation passed: {len(problems)} problems")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
