#!/usr/bin/env python3
"""
CLI Tool to bootstrap new LeetCode problem solutions with boilerplate.
Usage:
    python3 scripts/new_problem.py -n 1 -t "Two Sum" -d Easy -c "Arrays & Hashing" -l cpp
Or simply run interactively:
    python3 scripts/new_problem.py
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parent.parent
SOLUTIONS_DIR = ROOT_DIR / "solutions"

TEMPLATES = {
    "cpp": """/**
 * Problem: {id}. {title}
 * Difficulty: {difficulty}
 * Category: {category}
 *
 * Time Complexity:  {time}
 * Space Complexity: {space}
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // TODO: Implement solution
};

int main() {
    Solution sol;
    cout << "Ready for testing {id}. {title}" << endl;
    return 0;
}
""",
    "c": """/**
 * Problem: {id}. {title}
 * Difficulty: {difficulty}
 * Category: {category}
 *
 * Time Complexity:  {time}
 * Space Complexity: {space}
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// TODO: Implement solution

int main(void) {
    printf("Ready for testing {id}. {title}\\n");
    return 0;
}
""",
    "py": """\"\"\"
Problem: {id}. {title}
Difficulty: {difficulty}
Category: {category}

Time Complexity:  {time}
Space Complexity: {space}
\"\"\"

from typing import List, Optional


class Solution:
    pass


if __name__ == "__main__":
    sol = Solution()
    print("Ready for testing {id}. {title}")
"""
}

EXT_MAP = {
    "cpp": "solution.cpp",
    "c": "solution.c",
    "py": "solution.py",
}

README_TEMPLATE = """# {id}. {title}

**Difficulty:** {difficulty}  
**Category:** {category}  
**LeetCode Link:** [{title}](https://leetcode.com/problems/{slug}/)  

---

## 📌 Problem Description

> [Add problem description or examples here]

---

## 💡 Intuition & Approach

### Approach: 
1. 
2. 
3. 

---

## ⚡ Complexity Analysis

- **Time Complexity:** `{time}` — 
- **Space Complexity:** `{space}` — 

---

## 📂 Solutions

- [Solution Source]({sol_file})
"""


def slugify(text: str) -> str:
    text = text.lower()
    text = re.sub(r"[^a-z0-9]+", "-", text)
    return text.strip("-")


def main():
    parser = argparse.ArgumentParser(description="Create boilerplate for a new LeetCode problem.")
    parser.add_argument("-n", "--number", type=int, help="LeetCode Problem ID (e.g. 1)")
    parser.add_argument("-t", "--title", type=str, help="Problem Title (e.g. Two Sum)")
    parser.add_argument("-d", "--difficulty", choices=["Easy", "Medium", "Hard"], default="Easy", help="Difficulty")
    parser.add_argument("-c", "--category", type=str, default="General", help="Category / Topic (e.g. Arrays & Hashing)")
    parser.add_argument("-l", "--lang", choices=["cpp", "c", "py"], default="cpp", help="Language (cpp, c, py)")
    parser.add_argument("--time", type=str, default="O(N)", help="Time complexity (default O(N))")
    parser.add_argument("--space", type=str, default="O(1)", help="Space complexity (default O(1))")

    args = parser.parse_args()

    # Interactive fallback
    if args.number is None:
        try:
            num_input = input("Problem Number (e.g. 1): ").strip()
            args.number = int(num_input)
            args.title = input("Problem Title (e.g. Two Sum): ").strip()
            args.difficulty = input("Difficulty [Easy/Medium/Hard] (default Easy): ").strip().capitalize() or "Easy"
            args.category = input("Category (e.g. Arrays & Hashing): ").strip() or "General"
            args.lang = input("Language [cpp/c/py] (default cpp): ").strip().lower() or "cpp"
        except (KeyboardInterrupt, EOFError):
            print("\nAborted.")
            sys.exit(1)

    slug = slugify(args.title)
    folder_name = f"{args.number:04d}-{slug}"
    target_dir = SOLUTIONS_DIR / folder_name
    target_dir.mkdir(parents=True, exist_ok=True)

    sol_filename = EXT_MAP.get(args.lang, f"solution.{args.lang}")
    sol_file = target_dir / sol_filename
    readme_file = target_dir / "README.md"

    # Create solution file if it doesn't exist
    if not sol_file.exists():
        template = TEMPLATES.get(args.lang, "// TODO: Solution")
        sol_content = template.format(
            id=args.number,
            title=args.title,
            difficulty=args.difficulty,
            category=args.category,
            time=args.time,
            space=args.space
        )
        sol_file.write_text(sol_content, encoding="utf-8")
        print(f"✓ Created: {sol_file.relative_to(ROOT_DIR)}")

    # Create README.md if it doesn't exist
    if not readme_file.exists():
        readme_content = README_TEMPLATE.format(
            id=args.number,
            title=args.title,
            difficulty=args.difficulty,
            category=args.category,
            slug=slug,
            time=args.time,
            space=args.space,
            sol_file=sol_filename
        )
        readme_file.write_text(readme_content, encoding="utf-8")
        print(f"✓ Created: {readme_file.relative_to(ROOT_DIR)}")

    # Automatically refresh main README
    update_script = ROOT_DIR / "scripts" / "update_readme.py"
    if update_script.exists():
        subprocess.run([sys.executable, str(update_script)])

    print(f"\n🚀 Problem #{args.number} setup complete! Location: solutions/{folder_name}/")


if __name__ == "__main__":
    main()
