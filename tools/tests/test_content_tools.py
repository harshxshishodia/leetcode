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

    def test_future_ranges_are_discovered_and_packaged(self) -> None:
        problem = self.root / "4001-5000" / "4001-4100" / "4001. Future Problem"
        problem.mkdir(parents=True)
        (problem / "README.md").write_text(
            "# 4001. Future Problem\n\nFuture description.\n\n**Difficulty:** Medium\n",
            encoding="utf-8",
        )
        approach = problem / "Approach 1"
        approach.mkdir()
        (approach / "main.py").write_text("class Solution: pass", encoding="utf-8")

        problems, errors = validate(self.root)

        self.assertEqual([], errors)
        self.assertIn(4001, [problem.number for problem in problems])

        output = self.root / "future-dist"
        build(self.root, output, "future-version", "2026-01-01T00:00:00Z")
        remote_manifest = json.loads((output / "manifest.json").read_text(encoding="utf-8"))
        indexed_paths = {item["path"] for item in remote_manifest["files"]}
        future_solution = "leetcode_seed/output/4001-4100/4001.json"
        self.assertIn(future_solution, indexed_paths)
        with zipfile.ZipFile(output / "content-package.zip") as archive:
            self.assertIn(future_solution, archive.namelist())

    def test_builder_packages_approach_code_deterministically_without_modifying_source_json(self) -> None:
        source_json = self.root / "existing.json"
        original_json = b'{"platform":"LeetCode"}\n'
        source_json.write_bytes(original_json)
        approach = self.problem / "Approach 1"
        approach.mkdir()
        empty_approach = self.problem / "Approach 2"
        empty_approach.mkdir()
        (empty_approach / "main.cpp").write_text("", encoding="utf-8")
        source_code = "class Solution { public: int answer() { return 42; } };"
        (approach / "main.cpp").write_text(source_code, encoding="utf-8")
        first = self.root / "dist-one"
        second = self.root / "dist-two"

        build(self.root, first, "fixed-version", "2026-01-01T00:00:00Z")
        build(self.root, second, "fixed-version", "2026-01-01T00:00:00Z")

        self.assertEqual(sha256_file(first / "content-package.zip"), sha256_file(second / "content-package.zip"))
        self.assertEqual(original_json, source_json.read_bytes())
        remote_manifest = json.loads((first / "manifest.json").read_text(encoding="utf-8"))
        indexed_files = {item["path"]: item for item in remote_manifest["files"]}
        solution_path = "leetcode_seed/output/0001-0100/0001.json"
        self.assertIn("leetcode_seed/manifest.json", indexed_files)
        self.assertIn(solution_path, indexed_files)
        self.assertEqual(
            indexed_files[solution_path]["sha256"],
            sha256_file(first / indexed_files[solution_path]["file"]),
        )
        with zipfile.ZipFile(first / "content-package.zip") as archive:
            names = archive.namelist()
            self.assertIn("leetcode_seed/manifest.json", names)
            self.assertIn("leetcode_seed/output/0001-0100/0001.json", names)
            self.assertFalse(any("Approach" in name or name.endswith("main.cpp") for name in names))
            manifest = json.loads(archive.read("leetcode_seed/manifest.json"))
            self.assertEqual(1, manifest["batchedProblemCount"])
            solution = json.loads(archive.read("leetcode_seed/output/0001-0100/0001.json"))
            self.assertEqual(source_code, solution[0]["solutions"]["approach_1"]["cpp"])
            self.assertEqual({}, solution[0]["solutions"]["approach_2"])

    def test_builder_skips_empty_approach_placeholders(self) -> None:
        approach = self.problem / "Approach 1"
        approach.mkdir()
        (approach / "main.cpp").write_text("", encoding="utf-8")
        output = self.root / "dist"

        build(self.root, output, "fixed-version", "2026-01-01T00:00:00Z")

        with zipfile.ZipFile(output / "content-package.zip") as archive:
            self.assertNotIn("leetcode_seed/output/0001-0100/0001.json", archive.namelist())

    def test_builder_merges_solution_directory_languages_into_numbered_approach(self) -> None:
        approach = self.problem / "Approach 3"
        approach.mkdir()
        (approach / "main.cpp").write_text("cpp from canonical approach", encoding="utf-8")
        solution = self.problem / "Solution 3"
        solution.mkdir()
        (solution / "main.cpp").write_text("cpp from alias", encoding="utf-8")
        (solution / "main.py").write_text("python code", encoding="utf-8")
        (solution / "main.java").write_text("java code", encoding="utf-8")
        (solution / "main.go").write_text("go code", encoding="utf-8")
        (solution / "main.rs").write_text("rust code", encoding="utf-8")
        (solution / "main.kt").write_text("kotlin code", encoding="utf-8")
        (solution / "main.pandas.py").write_text("pandas code", encoding="utf-8")
        (solution / "main.postgresql.sql").write_text("postgres code", encoding="utf-8")
        (solution / "main.ex").write_text("elixir code", encoding="utf-8")
        output = self.root / "dist"

        build(self.root, output, "fixed-version", "2026-01-01T00:00:00Z")

        with zipfile.ZipFile(output / "content-package.zip") as archive:
            payload = json.loads(archive.read("leetcode_seed/output/0001-0100/0001.json"))
            languages = payload[0]["solutions"]["approach_3"]
            self.assertEqual(
                {
                    "cpp": "cpp from canonical approach",
                    "python": "python code",
                    "java": "java code",
                    "go": "go code",
                    "rust": "rust code",
                    "kotlin": "kotlin code",
                    "pandas": "pandas code",
                    "postgresql": "postgres code",
                    "elixir": "elixir code",
                },
                languages,
            )

    def test_builder_normalizes_html_markdown_and_local_images(self) -> None:
        image_dir = self.root / "images"
        image_dir.mkdir()
        (image_dir / "two-sum.png").write_bytes(b"\x89PNG\r\n\x1a\n")
        (self.problem / "README.md").write_text(
            """# 1. Two Sum

<p>Given an array of integers <code>nums</code> and an integer <code>target</code>. Calculate the <span data-keyword="gcd-function">GCD</span> in <strong>ascending</strong> order up to 10<sup>5</sup>.Â&nbsp;</p>
<table>
  <thead><tr><th>Symbol</th><th>Value</th></tr></thead>
  <tbody>
    <tr><td>I</td><td>1</td></tr>
    <tr><td>V</td><td>5</td></tr>
  </tbody>
</table>
<ul><li>Return indices of the two numbers.</li></ul>
<p><strong class="example">Example 1:</strong></p>
<img src="../../../images/two-sum.png" />
<pre><strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]</pre>

**Difficulty:** Easy

**Topics:** Array, Hash Table
""",
            encoding="utf-8",
        )
        output = self.root / "dist"

        build(self.root, output, "fixed-version", "2026-01-01T00:00:00Z")

        with zipfile.ZipFile(output / "content-package.zip") as archive:
            batch = json.loads(archive.read("leetcode_seed/batches/leetcode_1_1.json"))
            entry = batch["entries"][0]
            blocks = entry["contentBlocks"]
            rich_text = "\n".join(block.get("text", "") for block in blocks)
            self.assertTrue(any(block["type"] == "image" for block in blocks))
            self.assertTrue(any(block["type"] == "code" and "Input:" in block["text"] for block in blocks))
            self.assertFalse(any("<p>" in block.get("text", "") for block in blocks))
            self.assertIn("`nums`", rich_text)
            self.assertIn("[GCD](leetcode-keyword)", rich_text)
            self.assertIn("**ascending**", rich_text)
            self.assertIn("10⁵", rich_text)
            self.assertIn("| Symbol | Value |", rich_text)
            self.assertIn("| --- | --- |", rich_text)
            self.assertIn("| I | 1 |", rich_text)
            self.assertIn("| V | 5 |", rich_text)
            self.assertNotIn("<table", rich_text)
            self.assertNotIn("Â", rich_text)
            self.assertIn("[[img:leetcode_seed/assets/problems/0001-two-sum/two-sum.png]]", entry["problem"])
            self.assertIn("leetcode_seed/assets/problems/0001-two-sum/two-sum.png", archive.namelist())


if __name__ == "__main__":
    unittest.main()
