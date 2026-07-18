from __future__ import annotations

import json
import sys
import tempfile
import unittest
import zipfile
from pathlib import Path


TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))

from build_mobile_package import build, sha256_file  # noqa: E402
from validate_content import validate  # noqa: E402


README = """# 1. Two Sum

Given two values, return their indices.

**Difficulty:** Easy

**Topics:** Array, Hash Table
"""


class ContentToolsTest(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)
        self.problem = self.root / "1-1000" / "1-100" / "1. Two Sum"
        self.problem.mkdir(parents=True)
        (self.problem / "README.md").write_text(README, encoding="utf-8")

    def tearDown(self) -> None:
        self.temporary.cleanup()

    def test_validator_reports_duplicate_problem_id(self) -> None:
        duplicate = self.root / "1001-2000" / "1001-1100" / "1. Duplicate"
        duplicate.mkdir(parents=True)
        (duplicate / "README.md").write_text(README, encoding="utf-8")

        _, errors = validate(self.root)

        self.assertTrue(any("duplicate problem ID 1" in error for error in errors))

    def test_validator_accepts_parentheses_inside_category_link(self) -> None:
        problem = self.root / "1-1000" / "1-100" / "69. Sqrt(x)"
        problem.mkdir(parents=True)
        (problem / "README.md").write_text(
            "# 69. Sqrt(x)\n\n**Difficulty:** Easy\n",
            encoding="utf-8",
        )
        category = self.root / "category"
        category.mkdir()
        (category / "math.md").write_text(
            "[69. Sqrt(x)](../1-1000/1-100/69.%20Sqrt(x)/README.md)\n",
            encoding="utf-8",
        )

        _, errors = validate(self.root)

        self.assertEqual([], errors)

    def test_builder_is_deterministic_and_does_not_modify_existing_json(self) -> None:
        source_json = self.root / "existing.json"
        original_json = b'{"platform":"LeetCode"}\n'
        source_json.write_bytes(original_json)
        approach = self.problem / "Approach 1"
        approach.mkdir()
        (approach / "main.cpp").write_text("// must not be packaged", encoding="utf-8")
        first = self.root / "dist-one"
        second = self.root / "dist-two"

        build(self.root, first, "fixed-version", "2026-01-01T00:00:00Z")
        build(self.root, second, "fixed-version", "2026-01-01T00:00:00Z")

        self.assertEqual(sha256_file(first / "content-package.zip"), sha256_file(second / "content-package.zip"))
        self.assertEqual(original_json, source_json.read_bytes())
        with zipfile.ZipFile(first / "content-package.zip") as archive:
            names = archive.namelist()
            self.assertIn("leetcode_seed/manifest.json", names)
            self.assertFalse(any("Approach" in name or name.endswith("main.cpp") for name in names))
            manifest = json.loads(archive.read("leetcode_seed/manifest.json"))
            self.assertEqual(1, manifest["batchedProblemCount"])


if __name__ == "__main__":
    unittest.main()
