#!/usr/bin/env python3
"""Publish generated mobile content to S3-compatible storage when configured."""

from __future__ import annotations

import argparse
import mimetypes
import os
import sys
from pathlib import Path


REQUIRED_ENVIRONMENT = (
    "CONTENT_STORAGE_ENDPOINT",
    "CONTENT_STORAGE_ACCESS_KEY",
    "CONTENT_STORAGE_SECRET_KEY",
    "CONTENT_STORAGE_BUCKET",
)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, default=Path("generated-mobile-content"))
    parser.add_argument("--prefix", default="latest")
    args = parser.parse_args()
    missing_files = [name for name in ("content-package.zip", "manifest.json", "checksums.sha256") if not (args.input / name).is_file()]
    if missing_files:
        print(f"Missing generated file(s): {', '.join(missing_files)}", file=sys.stderr)
        return 1
    missing_environment = [name for name in REQUIRED_ENVIRONMENT if not os.environ.get(name)]
    if missing_environment:
        print("S3-compatible storage is not configured; GitHub Actions artifact is the publishing fallback.")
        return 0

    import boto3

    client = boto3.client(
        "s3",
        endpoint_url=os.environ["CONTENT_STORAGE_ENDPOINT"],
        aws_access_key_id=os.environ["CONTENT_STORAGE_ACCESS_KEY"],
        aws_secret_access_key=os.environ["CONTENT_STORAGE_SECRET_KEY"],
        region_name=os.environ.get("CONTENT_STORAGE_REGION", "auto"),
    )
    bucket = os.environ["CONTENT_STORAGE_BUCKET"]
    # Publish immutable objects before the manifest so clients never observe a
    # manifest that references payloads which are not available yet.
    for path in sorted((args.input / "objects").rglob("*")):
        if not path.is_file():
            continue
        relative = path.relative_to(args.input).as_posix()
        content_type = mimetypes.guess_type(path.name)[0] or "application/octet-stream"
        client.upload_file(
            str(path),
            bucket,
            f"{args.prefix.strip('/')}/{relative}",
            ExtraArgs={"ContentType": content_type, "CacheControl": "public, max-age=31536000, immutable"},
        )
    content_types = {
        "content-package.zip": "application/zip",
        "checksums.sha256": "text/plain",
        "manifest.json": "application/json",
    }
    for name, content_type in content_types.items():
        client.upload_file(
            str(args.input / name),
            bucket,
            f"{args.prefix.strip('/')}/{name}",
            ExtraArgs={"ContentType": content_type, "CacheControl": "no-cache"},
        )
    public_base = os.environ.get("CONTENT_PUBLIC_BASE_URL", "").rstrip("/")
    if public_base:
        print(f"Published manifest: {public_base}/{args.prefix.strip('/')}/manifest.json")
    else:
        print(f"Published mobile content to bucket {bucket!r} under {args.prefix.strip('/')!r}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
