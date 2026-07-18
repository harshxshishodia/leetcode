#!/usr/bin/env python3
"""Build a deterministic mobile package from the validated LeetCode content tree."""

from __future__ import annotations

import argparse
import hashlib
import html
import json
import os
import re
import shutil
import subprocess
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path
from urllib.parse import unquote, urlparse

from validate_content import Problem, validate


MARKDOWN_IMAGE = re.compile(r"!\[(?P<alt>[^\]]*)]\((?P<target><[^>]+>|[^)\s]+)(?:\s+['\"].*?['\"])?\)")
HTML_IMAGE = re.compile(r"<img\b[^>]*\bsrc\s*=\s*['\"](?P<target>[^'\"]+)['\"][^>]*>", re.IGNORECASE)
PRE_BLOCK = re.compile(r"<pre\b[^>]*>(?P<content>.*?)</pre>", re.IGNORECASE | re.DOTALL)
HTML_TABLE = re.compile(r"<table\b[^>]*>.*?</table\s*>", re.IGNORECASE | re.DOTALL)
HTML_TABLE_ROW = re.compile(r"<tr\b[^>]*>(?P<content>.*?)</tr\s*>", re.IGNORECASE | re.DOTALL)
HTML_TABLE_CELL = re.compile(r"<t[hd]\b[^>]*>(?P<content>.*?)</t[hd]\s*>", re.IGNORECASE | re.DOTALL)
HTML_KEYWORD_SPAN = re.compile(
    r"<span\b(?=[^>]*\bdata-keyword\s*=)[^>]*>(?P<content>.*?)</span\s*>",
    re.IGNORECASE | re.DOTALL,
)
HTML_LINK = re.compile(
    r"<a\b[^>]*\bhref\s*=\s*['\"](?P<target>[^'\"]+)['\"][^>]*>(?P<content>.*?)</a\s*>",
    re.IGNORECASE | re.DOTALL,
)
HTML_SUPERSCRIPT = re.compile(r"<sup\b[^>]*>(?P<content>.*?)</sup\s*>", re.IGNORECASE | re.DOTALL)
NON_SLUG = re.compile(r"[^a-z0-9]+")
FIXED_ZIP_TIME = (1980, 1, 1, 0, 0, 0)
SOLUTION_DIRECTORY = re.compile(r"^(?:Approach|Solution)\s+(?P<number>\d+)$", re.IGNORECASE)
LANGUAGE_BY_SUFFIX = {
    ".py": "python",
    ".py3": "python3",
    ".java": "java",
    ".cpp": "cpp",
    ".cc": "cpp",
    ".cxx": "cpp",
    ".c": "c",
    ".js": "javascript",
    ".mjs": "vanilla_js",
    ".jsx": "react",
    ".ts": "typescript",
    ".cs": "csharp",
    ".php": "php",
    ".swift": "swift",
    ".kt": "kotlin",
    ".kts": "kotlin",
    ".dart": "dart",
    ".go": "go",
    ".rb": "ruby",
    ".scala": "scala",
    ".rs": "rust",
    ".rkt": "racket",
    ".erl": "erlang",
    ".ex": "elixir",
    ".exs": "elixir",
    ".mysql": "mysql",
    ".tsql": "mssql",
    ".pls": "oracle",
    ".pgsql": "postgresql",
    ".sql": "sql",
    ".sh": "bash",
}
LANGUAGE_BY_NAME_SUFFIX = {
    ".pandas.py": "pandas",
    ".python3.py": "python3",
    ".mysql.sql": "mysql",
    ".mssql.sql": "mssql",
    ".oracle.sql": "oracle",
    ".postgresql.sql": "postgresql",
    ".postgres.sql": "postgresql",
    ".react.jsx": "react",
    ".vanilla.js": "vanilla_js",
}
MAX_APPROACHES = 20
LEETCODE_KEYWORD_LINK = "leetcode-keyword"
SUPERSCRIPT_CHARACTERS = {
    "0": "⁰",
    "1": "¹",
    "2": "²",
    "3": "³",
    "4": "⁴",
    "5": "⁵",
    "6": "⁶",
    "7": "⁷",
    "8": "⁸",
    "9": "⁹",
    "+": "⁺",
    "-": "⁻",
    "=": "⁼",
    "(": "⁽",
    ")": "⁾",
    "i": "ⁱ",
    "n": "ⁿ",
}
try:
    import zlib  # noqa: F401
    ZIP_COMPRESSION = zipfile.ZIP_DEFLATED
    ZIP_COMPRESSLEVEL = 9
except ImportError:
    ZIP_COMPRESSION = zipfile.ZIP_STORED
    ZIP_COMPRESSLEVEL = None


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def slugify(value: str) -> str:
    return NON_SLUG.sub("-", value.lower()).strip("-") or "problem"


def source_version(root: Path, problems: list[Problem]) -> str:
    configured = os.environ.get("GITHUB_SHA", "").strip()
    if configured:
        return configured
    try:
        value = subprocess.check_output(
            ["git", "-C", str(root), "rev-parse", "HEAD"],
            stderr=subprocess.DEVNULL,
            text=True,
        ).strip()
        if value:
            return value
    except (OSError, subprocess.CalledProcessError):
        pass
    digest = hashlib.sha256()
    for problem in problems:
        digest.update(problem.readme.relative_to(root).as_posix().encode())
        digest.update(problem.readme.read_bytes())
    return f"local-{digest.hexdigest()[:24]}"


def metadata(text: str, name: str, default: str = "") -> str:
    match = re.search(rf"^\*\*{re.escape(name)}:\*\*\s*(.+?)\s*$", text, re.MULTILINE | re.IGNORECASE)
    return match.group(1).strip() if match else default


def resolve_local_image(root: Path, readme: Path, target: str) -> Path | None:
    parsed = urlparse(target.strip("<>"))
    if parsed.scheme or target.startswith("//") or not parsed.path:
        return None
    candidate = (readme.parent / unquote(parsed.path)).resolve()
    try:
        candidate.relative_to(root)
    except ValueError:
        return None
    return candidate if candidate.is_file() else None


def image_spans(text: str):
    spans = []
    for match in MARKDOWN_IMAGE.finditer(text):
        spans.append((match.start(), match.end(), match.group("target").strip("<>"), match.group("alt")))
    for match in HTML_IMAGE.finditer(text):
        spans.append((match.start(), match.end(), match.group("target"), "Problem image"))
    return sorted(spans, key=lambda value: value[0])


def strip_tags(value: str) -> str:
    return re.sub(r"<[^>]+>", "", value, flags=re.DOTALL)


def repair_leetcode_text(value: str) -> str:
    return value.replace("\u00c2\u00a0", " ").replace("\u00c2 ", " ").replace("\u00a0", " ")


def superscript_text(value: str) -> str:
    plain = repair_leetcode_text(html.unescape(strip_tags(value))).strip()
    if not plain:
        return ""
    if all(character in SUPERSCRIPT_CHARACTERS for character in plain):
        return "".join(SUPERSCRIPT_CHARACTERS[character] for character in plain)
    return f"^({plain})"


def convert_inline_markup(value: str) -> str:
    text = HTML_KEYWORD_SPAN.sub(
        lambda match: f"[{match.group('content')}]({LEETCODE_KEYWORD_LINK})",
        value,
    )
    text = HTML_LINK.sub(
        lambda match: f"[{match.group('content')}]({match.group('target')})",
        text,
    )
    text = re.sub(r"(?i)<strong\b[^>]*>|<b\b[^>]*>", "**", text)
    text = re.sub(r"(?i)</strong\s*>|</b\s*>", "**", text)
    text = re.sub(r"(?i)<em\b[^>]*>|<i\b[^>]*>", "*", text)
    text = re.sub(r"(?i)</em\s*>|</i\s*>", "*", text)
    text = re.sub(r"(?i)<code\b[^>]*>", "`", text)
    text = re.sub(r"(?i)</code\s*>", "`", text)
    return HTML_SUPERSCRIPT.sub(lambda match: superscript_text(match.group("content")), text)


def normalize_table_cell(value: str) -> str:
    text = re.sub(r"(?i)<br\s*/?>", " ", value)
    text = convert_inline_markup(text)
    text = repair_leetcode_text(html.unescape(strip_tags(text)))
    text = re.sub(r"\s+", " ", text).strip()
    return text.replace("|", r"\|")


def html_table_to_markdown(match: re.Match[str]) -> str:
    rows = []
    for row_match in HTML_TABLE_ROW.finditer(match.group(0)):
        cells = [
            normalize_table_cell(cell_match.group("content"))
            for cell_match in HTML_TABLE_CELL.finditer(row_match.group("content"))
        ]
        if cells:
            rows.append(cells)
    if not rows:
        return repair_leetcode_text(html.unescape(strip_tags(match.group(0))))

    column_count = max(len(row) for row in rows)

    def markdown_row(row: list[str]) -> str:
        padded = row + [""] * (column_count - len(row))
        return "| " + " | ".join(padded) + " |"

    rendered = [markdown_row(rows[0]), markdown_row(["---"] * column_count)]
    rendered.extend(markdown_row(row) for row in rows[1:])
    return "\n\n" + "\n".join(rendered) + "\n\n"


def normalize_markup_text(value: str) -> str:
    if not value.strip():
        return ""
    text = repair_leetcode_text(value.replace("\r\n", "\n"))
    text = HTML_TABLE.sub(html_table_to_markdown, text)
    text = re.sub(r"(?i)<br\s*/?>", "\n", text)
    text = re.sub(r"(?i)</p\s*>", "\n\n", text)
    text = re.sub(r"(?i)<p\b[^>]*>", "\n\n", text)
    text = re.sub(r"(?i)<li\b[^>]*>", "\n- ", text)
    text = re.sub(r"(?i)</li\s*>", "", text)
    text = re.sub(r"(?i)</?(ul|ol)\b[^>]*>", "\n", text)
    text = convert_inline_markup(text)
    text = strip_tags(text)
    text = repair_leetcode_text(html.unescape(text))
    text = "\n".join(line.rstrip() for line in text.splitlines())
    return re.sub(r"\n{3,}", "\n\n", text).strip()


def trim_readme_chrome(value: str) -> str:
    lines = value.replace("\r\n", "\n").splitlines()
    first_content = next((index for index, line in enumerate(lines) if line.strip()), None)
    if first_content is not None and re.match(r"^#{1,3}\s+(\d+\.\s*)?.+", lines[first_content].strip()):
        lines[first_content] = ""
    metadata_index = next(
        (
            index
            for index, line in enumerate(lines)
            if re.match(r"(?i)^\*{0,2}(Difficulty|Topics)\s*:\*{0,2}.*", line.strip())
        ),
        None,
    )
    if metadata_index is not None:
        cut_index = metadata_index
        previous_content = next(
            (index for index in range(metadata_index - 1, -1, -1) if lines[index].strip()),
            None,
        )
        if previous_content is not None and re.match(r"^-{3,}$", lines[previous_content].strip()):
            cut_index = previous_content
        lines = lines[:cut_index]
    return "\n".join(lines).strip()


def structured_text_blocks(value: str) -> list[dict]:
    blocks: list[dict] = []
    cursor = 0
    for match in PRE_BLOCK.finditer(value):
        leading = normalize_markup_text(value[cursor:match.start()])
        if leading:
            blocks.append({"type": "text", "text": leading})
        code = repair_leetcode_text(html.unescape(strip_tags(match.group("content")))).strip("\n")
        if code.strip():
            blocks.append({"type": "code", "text": code})
        cursor = match.end()
    trailing = normalize_markup_text(value[cursor:])
    if trailing:
        blocks.append({"type": "text", "text": trailing})
    return blocks


def append_text_blocks(blocks: list[dict], value: str) -> None:
    for block in structured_text_blocks(value):
        block["sequence"] = len(blocks)
        blocks.append(block)


def problem_text_from_blocks(blocks: list[dict]) -> str:
    parts = []
    for block in blocks:
        if block.get("type") == "image":
            parts.append(f"[[img:{block.get('localPath', '')}]]")
        else:
            text = str(block.get("text", "")).strip()
            if text:
                parts.append(text)
    return "\n\n".join(part for part in parts if part).strip()


def read_problem_solutions(problem: Problem) -> dict[str, dict[str, str]]:
    """Read Approach/Solution 1..20 source files without packaging raw folders."""
    solutions: dict[str, dict[str, str]] = {}
    has_code = False
    directories = []
    for candidate in problem.readme.parent.iterdir():
        match = SOLUTION_DIRECTORY.fullmatch(candidate.name) if candidate.is_dir() else None
        if match is None:
            continue
        number = int(match.group("number"))
        if 1 <= number <= MAX_APPROACHES:
            directories.append((number, candidate))

    for number, directory in sorted(directories, key=lambda item: (item[0], item[1].name.casefold())):
        approach_key = f"approach_{number}"
        languages = solutions.setdefault(approach_key, {})
        for source in sorted(directory.iterdir(), key=lambda path: path.name.casefold()):
            if not source.is_file():
                continue
            source_name = source.name.casefold()
            language = next(
                (
                    language_key
                    for name_suffix, language_key in LANGUAGE_BY_NAME_SUFFIX.items()
                    if source_name.endswith(name_suffix)
                ),
                LANGUAGE_BY_SUFFIX.get(source.suffix.lower()),
            )
            if language is None:
                continue
            code = source.read_text(encoding="utf-8").strip()
            if code:
                # Approach N remains the canonical spelling if both directory aliases
                # contain the same language; unique languages are merged.
                languages.setdefault(language, code)
                has_code = True
    return solutions if has_code else {}


def solution_asset_path(problem_number: int) -> str:
    start = ((problem_number - 1) // 100) * 100 + 1
    end = start + 99
    return f"output/{start:04d}-{end:04d}/{problem_number:04d}.json"


def build_problem(root: Path, seed_root: Path, problem: Problem) -> dict:
    raw_text = problem.readme.read_text(encoding="utf-8")
    difficulty = metadata(raw_text, "Difficulty", "Medium").split("(", 1)[0].strip()
    topics = [topic.strip() for topic in metadata(raw_text, "Topics").split(",") if topic.strip()]
    text = trim_readme_chrome(raw_text)
    problem_slug = slugify(problem.name)
    destination = seed_root / "assets" / "problems" / f"{problem.number:04d}-{problem_slug}"
    assets = []
    blocks = []
    cursor = 0
    used_names: set[str] = set()

    for start, end, target, alt in image_spans(text):
        if start < cursor:
            continue
        image = resolve_local_image(root, problem.readme, target)
        if image is None:
            continue
        leading = text[cursor:start]
        append_text_blocks(blocks, leading)

        safe_name = re.sub(r"[^A-Za-z0-9._-]+", "-", image.name).strip("-") or "image"
        name_key = safe_name.casefold()
        if name_key in used_names:
            stem, suffix = Path(safe_name).stem, Path(safe_name).suffix
            safe_name = f"{stem}-{sha256_file(image)[:10]}{suffix}"
        used_names.add(safe_name.casefold())
        destination.mkdir(parents=True, exist_ok=True)
        copied = destination / safe_name
        shutil.copyfile(image, copied)
        data = copied.read_bytes()
        local_path = f"leetcode_seed/assets/problems/{problem.number:04d}-{problem_slug}/{safe_name}"
        asset = {
            "assetIndex": len(assets),
            "bytes": len(data),
            "contentType": content_type(copied.suffix),
            "localPath": local_path,
            "originalUrl": target,
            "sha256": sha256_bytes(data),
        }
        assets.append(asset)
        blocks.append({
            "sequence": len(blocks),
            "type": "image",
            "alt": alt or "Problem image",
            "localPath": local_path,
            "sha256": asset["sha256"],
            "contentType": asset["contentType"],
        })
        cursor = end

    trailing = text[cursor:]
    append_text_blocks(blocks, trailing)
    if not blocks:
        append_text_blocks(blocks, text)
    problem_text = problem_text_from_blocks(blocks)

    solutions = read_problem_solutions(problem)
    if solutions:
        write_json(seed_root / solution_asset_path(problem.number), [{
            "leetcode_no": problem.number,
            "name": problem.name,
            "solutions": solutions,
        }])

    return {
        "schemaVersion": 2,
        "sequenceIndex": problem.number,
        "problemNumber": problem.number,
        "problemName": problem.name,
        "problemSlug": problem_slug,
        "problemLink": f"https://leetcode.com/problems/{problem_slug}/",
        "difficulty": difficulty,
        "paidOnly": "premium" in metadata(text, "Difficulty").lower(),
        "problem": problem_text,
        "contentHtml": "",
        "contentHtmlLocal": "",
        "categories": topics,
        "contentBlocks": blocks,
        "descriptionBlocks": blocks,
        "examples": [],
        "constraintBlocks": [],
        "assets": assets,
        "solutionApproaches": list(solutions),
        "databaseEntry": {
            "problemNumber": problem.number,
            "problemName": problem.name,
            "problemLink": f"https://leetcode.com/problems/{problem_slug}/",
            "difficulty": difficulty,
            "revisionPlanHours": [1, 24, 168, 336, 672],
            "revisionAnchorAt": 0,
            "revisionCount": 0,
            "revisionDates": [],
            "lastRevisionAt": 0,
            "problem": problem_text,
            "testCases": "",
            "solutionCode": "",
            "categories": topics,
            "createdAt": 0,
            "updatedAt": 0,
        },
    }


def content_type(suffix: str) -> str:
    return {
        ".gif": "image/gif",
        ".jpeg": "image/jpeg",
        ".jpg": "image/jpeg",
        ".png": "image/png",
        ".svg": "image/svg+xml",
        ".webp": "image/webp",
    }.get(suffix.lower(), "application/octet-stream")


def write_json(path: Path, value: object) -> bytes:
    data = (json.dumps(value, ensure_ascii=False, sort_keys=True, separators=(",", ":")) + "\n").encode("utf-8")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)
    return data


def write_deterministic_zip(source: Path, destination: Path) -> None:
    zip_kwargs = {"compression": ZIP_COMPRESSION}
    if ZIP_COMPRESSLEVEL is not None:
        zip_kwargs["compresslevel"] = ZIP_COMPRESSLEVEL
    write_kwargs = {"compress_type": ZIP_COMPRESSION}
    if ZIP_COMPRESSLEVEL is not None:
        write_kwargs["compresslevel"] = ZIP_COMPRESSLEVEL
    with zipfile.ZipFile(destination, "w", **zip_kwargs) as archive:
        for path in sorted(source.rglob("*"), key=lambda item: item.relative_to(source).as_posix()):
            if not path.is_file():
                continue
            relative = path.relative_to(source).as_posix()
            info = zipfile.ZipInfo(relative, FIXED_ZIP_TIME)
            info.compress_type = ZIP_COMPRESSION
            info.external_attr = 0o100644 << 16
            archive.writestr(info, path.read_bytes(), **write_kwargs)


def build(content_root: Path, output: Path, version: str | None, generated_at: str | None) -> None:
    content_root = content_root.resolve()
    output = output.resolve()
    problems, errors = validate(content_root)
    if errors:
        for error in errors:
            print(f"ERROR: {error}", file=sys.stderr)
        raise SystemExit(1)
    content_version = version or source_version(content_root, problems)
    timestamp = generated_at or datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")

    staging = output.parent / f".{output.name}-staging"
    shutil.rmtree(staging, ignore_errors=True)
    staging.mkdir(parents=True)
    package_tree = staging / "package"
    seed_root = package_tree / "leetcode_seed"
    batch_root = seed_root / "batches"
    batch_metadata = []

    entries = [build_problem(content_root, seed_root, problem) for problem in problems]
    for index in range(0, len(entries), 100):
        batch_entries = entries[index:index + 100]
        start, end = batch_entries[0]["problemNumber"], batch_entries[-1]["problemNumber"]
        relative = f"batches/leetcode_{start}_{end}.json"
        data = write_json(batch_root / f"leetcode_{start}_{end}.json", {"schemaVersion": 2, "entries": batch_entries})
        batch_metadata.append({"file": relative, "sha256": sha256_bytes(data), "size": len(data)})

    write_json(seed_root / "manifest.json", {
        "schemaVersion": 2,
        "generatedAt": content_version,
        "batchedProblemCount": len(entries),
        "fetchedProblemCount": len(entries),
        "batches": batch_metadata,
    })
    package_file = staging / "content-package.zip"
    write_deterministic_zip(package_tree, package_file)
    package_hash = sha256_file(package_file)
    published_files = []
    for path in sorted(package_tree.rglob("*"), key=lambda item: item.relative_to(package_tree).as_posix()):
        if not path.is_file():
            continue
        relative = path.relative_to(package_tree).as_posix()
        file_hash = sha256_file(path)
        destination = staging / "objects" / file_hash
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists():
            shutil.copyfile(path, destination)
        published_files.append({
            "path": relative,
            "file": f"objects/{file_hash}",
            "sha256": file_hash,
            "size": path.stat().st_size,
        })
    remote_manifest = {
        "schemaVersion": 1,
        "contentVersion": content_version,
        "generatedAt": timestamp,
        "packageFile": "content-package.zip",
        "packageSha256": package_hash,
        "packageSize": package_file.stat().st_size,
        "files": published_files,
    }
    manifest_data = write_json(staging / "manifest.json", remote_manifest)
    checksums = (
        f"{package_hash}  content-package.zip\n"
        f"{sha256_bytes(manifest_data)}  manifest.json\n"
    )
    with (staging / "checksums.sha256").open("w", encoding="utf-8", newline="\n") as checksum_file:
        checksum_file.write(checksums)
    shutil.rmtree(package_tree)
    shutil.rmtree(output, ignore_errors=True)
    staging.replace(output)
    print(f"Built {output / 'content-package.zip'} ({len(entries)} problems, version {content_version})")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--content-root", type=Path, default=Path.cwd())
    parser.add_argument("--output", type=Path)
    parser.add_argument("--content-version")
    parser.add_argument("--generated-at")
    args = parser.parse_args()
    output = args.output or args.content_root / "generated-mobile-content"
    build(args.content_root, output, args.content_version, args.generated_at)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
