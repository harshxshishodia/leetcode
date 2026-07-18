#!/usr/bin/env python3
"""Build a deterministic mobile package from the validated LeetCode content tree."""

from __future__ import annotations

import argparse
import hashlib
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
NON_SLUG = re.compile(r"[^a-z0-9]+")
FIXED_ZIP_TIME = (1980, 1, 1, 0, 0, 0)


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


def build_problem(root: Path, seed_root: Path, problem: Problem) -> dict:
    text = problem.readme.read_text(encoding="utf-8")
    difficulty = metadata(text, "Difficulty", "Medium").split("(", 1)[0].strip()
    topics = [topic.strip() for topic in metadata(text, "Topics").split(",") if topic.strip()]
    problem_slug = slugify(problem.name)
    destination = seed_root / "assets" / "problems" / f"{problem.number:04d}-{problem_slug}"
    assets = []
    blocks = []
    rewritten_parts = []
    cursor = 0
    used_names: set[str] = set()

    for start, end, target, alt in image_spans(text):
        if start < cursor:
            continue
        image = resolve_local_image(root, problem.readme, target)
        if image is None:
            continue
        leading = text[cursor:start]
        if leading.strip():
            blocks.append({"sequence": len(blocks), "type": "text", "text": leading})
        rewritten_parts.append(text[cursor:start])

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
        rewritten_parts.append(f"\n[[img:{local_path}]]\n")
        cursor = end

    trailing = text[cursor:]
    if trailing.strip():
        blocks.append({"sequence": len(blocks), "type": "text", "text": trailing})
    rewritten_parts.append(trailing)
    if not blocks:
        blocks.append({"sequence": 0, "type": "text", "text": text})

    return {
        "schemaVersion": 2,
        "sequenceIndex": problem.number,
        "problemNumber": problem.number,
        "problemName": problem.name,
        "problemSlug": problem_slug,
        "problemLink": f"https://leetcode.com/problems/{problem_slug}/",
        "difficulty": difficulty,
        "paidOnly": "premium" in metadata(text, "Difficulty").lower(),
        "problem": "".join(rewritten_parts),
        "contentHtml": "",
        "contentHtmlLocal": "",
        "categories": topics,
        "contentBlocks": blocks,
        "descriptionBlocks": blocks,
        "examples": [],
        "constraintBlocks": [],
        "assets": assets,
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
            "problem": "".join(rewritten_parts),
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
    with zipfile.ZipFile(destination, "w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as archive:
        for path in sorted(source.rglob("*"), key=lambda item: item.relative_to(source).as_posix()):
            if not path.is_file():
                continue
            relative = path.relative_to(source).as_posix()
            info = zipfile.ZipInfo(relative, FIXED_ZIP_TIME)
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o100644 << 16
            archive.writestr(info, path.read_bytes(), compress_type=zipfile.ZIP_DEFLATED, compresslevel=9)


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
    remote_manifest = {
        "schemaVersion": 1,
        "contentVersion": content_version,
        "generatedAt": timestamp,
        "packageFile": "content-package.zip",
        "packageSha256": package_hash,
        "packageSize": package_file.stat().st_size,
    }
    manifest_data = write_json(staging / "manifest.json", remote_manifest)
    checksums = (
        f"{package_hash}  content-package.zip\n"
        f"{sha256_bytes(manifest_data)}  manifest.json\n"
    )
    (staging / "checksums.sha256").write_text(checksums, encoding="utf-8", newline="\n")
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
