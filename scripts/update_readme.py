#!/usr/bin/env python3
"""
Automated README & Stats Generator for LeetCode Solutions.
Scans solutions directory and automatically updates:
- Total, Easy, Medium, Hard stats badges and table
- Comprehensive problem index table with links, difficulty, and complexities
"""

import os
import re
import sys
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parent.parent
SOLUTIONS_DIR = ROOT_DIR / "solutions"
README_PATH = ROOT_DIR / "README.md"

DIFFICULTY_BADGES = {
    "Easy": "![Easy](https://img.shields.io/badge/Easy-22c55e?style=flat-square)",
    "Medium": "![Medium](https://img.shields.io/badge/Medium-f59e0b?style=flat-square)",
    "Hard": "![Hard](https://img.shields.io/badge/Hard-ef4444?style=flat-square)",
}

LANG_MAP = {
    ".cpp": "C++",
    ".c": "C",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
}

def parse_metadata(readme_file: Path) -> dict:
    meta = {
        "id": 0,
        "title": "Unknown",
        "difficulty": "Easy",
        "category": "Algorithms",
        "time": "O(N)",
        "space": "O(1)",
        "url": "",
    }
    
    if not readme_file.exists():
        return meta

    content = readme_file.read_text(encoding="utf-8")
    
    # Extract metadata using regex or headers
    id_match = re.search(r"#\s*(\d+)\.\s*(.+)", content)
    if id_match:
        meta["id"] = int(id_match.group(1))
        meta["title"] = id_match.group(2).strip()

    diff_match = re.search(r"\*\*Difficulty:\*\*\s*(Easy|Medium|Hard)", content, re.IGNORECASE)
    if diff_match:
        meta["difficulty"] = diff_match.group(1).capitalize()

    cat_match = re.search(r"\*\*Category:\*\*\s*([^\n\r]+)", content)
    if cat_match:
        meta["category"] = cat_match.group(1).strip()

    time_match = re.search(r"\*\*Time Complexity:\*\*\s*([^\n\r]+)", content)
    if time_match:
        meta["time"] = time_match.group(1).strip()

    space_match = re.search(r"\*\*Space Complexity:\*\*\s*([^\n\r]+)", content)
    if space_match:
        meta["space"] = space_match.group(1).strip()

    url_match = re.search(r"\*\*LeetCode Link:\*\*\s*\[.*?\]\((https://leetcode\.com/problems/[^\)]+)\)", content)
    if url_match:
        meta["url"] = url_match.group(1)

    return meta


def collect_problems():
    problems = []
    if not SOLUTIONS_DIR.exists():
        return problems

    for entry in sorted(SOLUTIONS_DIR.iterdir()):
        if entry.is_dir() and not entry.name.startswith("."):
            readme_path = entry / "README.md"
            meta = parse_metadata(readme_path)
            
            # If ID was not parsed from title, try directory name
            if meta["id"] == 0:
                dir_id_match = re.match(r"^(\d+)", entry.name)
                if dir_id_match:
                    meta["id"] = int(dir_id_match.group(1))
                    meta["title"] = entry.name.split("-", 1)[-1].replace("-", " ").title()

            # Find solution files
            solutions = []
            for f in sorted(entry.iterdir()):
                ext = f.suffix
                if ext in LANG_MAP:
                    solutions.append({
                        "name": LANG_MAP[ext],
                        "rel_path": f"solutions/{entry.name}/{f.name}"
                    })

            meta["dir_name"] = entry.name
            meta["solutions"] = solutions
            problems.append(meta)

    # Sort by problem ID
    problems.sort(key=lambda x: x["id"])
    return problems


def generate_stats_markdown(problems):
    total = len(problems)
    easy = sum(1 for p in problems if p["difficulty"] == "Easy")
    medium = sum(1 for p in problems if p["difficulty"] == "Medium")
    hard = sum(1 for p in problems if p["difficulty"] == "Hard")

    easy_pct = f"{(easy / total * 100):.1f}%" if total else "0%"
    med_pct = f"{(medium / total * 100):.1f}%" if total else "0%"
    hard_pct = f"{(hard / total * 100):.1f}%" if total else "0%"

    return f"""| 🎯 Total Solved | 🟢 Easy | 🟡 Medium | 🔴 Hard |
| :---: | :---: | :---: | :---: |
| **{total}** | **{easy}** ({easy_pct}) | **{medium}** ({med_pct}) | **{hard}** ({hard_pct}) |"""


def generate_table_markdown(problems):
    headers = [
        "| # | Title | Difficulty | Category | Solution | Time | Space |",
        "| :-: | :-- | :-: | :-- | :-: | :-: | :-: |"
    ]
    rows = []
    for p in problems:
        pid = f"{p['id']:04d}"
        if p.get("url"):
            title = f"[{p['title']}]({p['url']})"
        else:
            title = f"[{p['title']}](solutions/{p['dir_name']}/)"

        diff_badge = DIFFICULTY_BADGES.get(p["difficulty"], p["difficulty"])
        
        # Format solution links
        if p["solutions"]:
            sol_links = ", ".join([f"[{s['name']}]({s['rel_path']})" for s in p["solutions"]])
        else:
            sol_links = f"[Notes](solutions/{p['dir_name']}/)"

        category = p.get("category", "General")
        time_c = p.get("time", "O(N)")
        space_c = p.get("space", "O(1)")

        rows.append(f"| `{pid}` | **{title}** | {diff_badge} | `{category}` | {sol_links} | `{time_c}` | `{space_c}` |")

    return "\n".join(headers + rows)


def update_readme(check_only=False):
    if not README_PATH.exists():
        print(f"Error: {README_PATH} not found.")
        sys.exit(1)

    content = README_PATH.read_text(encoding="utf-8")
    problems = collect_problems()

    stats_md = generate_stats_markdown(problems)
    table_md = generate_table_markdown(problems)

    # Replace STATS block
    new_content = re.sub(
        r"<!-- STATS:START -->.*?<!-- STATS:END -->",
        f"<!-- STATS:START -->\n{stats_md}\n<!-- STATS:END -->",
        content,
        flags=re.DOTALL
    )

    # Replace PROBLEMS block
    new_content = re.sub(
        r"<!-- PROBLEMS:START -->.*?<!-- PROBLEMS:END -->",
        f"<!-- PROBLEMS:START -->\n{table_md}\n<!-- PROBLEMS:END -->",
        new_content,
        flags=re.DOTALL
    )

    if check_only:
        if new_content != content:
            print("README.md is out of date! Run `python3 scripts/update_readme.py`.")
            sys.exit(1)
        else:
            print("README.md is up to date.")
            sys.exit(0)

    README_PATH.write_text(new_content, encoding="utf-8")
    print(f"✓ Updated README.md successfully with {len(problems)} solutions.")


if __name__ == "__main__":
    check_mode = "--check" in sys.argv
    update_readme(check_only=check_mode)
