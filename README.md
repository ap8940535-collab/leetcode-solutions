<div align="center">

# ⚡ LeetCode Solutions & Algorithm Practice

[![CI Build](https://github.com/ap8940535-collab/leetcode-solutions/actions/workflows/ci.yml/badge.svg)](https://github.com/ap8940535-collab/leetcode-solutions/actions)
[![Language](https://img.shields.io/badge/Language-C++%20%7C%20C-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://github.com/ap8940535-collab/leetcode-solutions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](LICENSE)
[![Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/)

<p align="center">
  A curated, professionally organized repository containing robust, well-documented solutions to LeetCode algorithmic problems in <b>C++</b> and <b>C</b> with detailed complexity analyses and intuitive explanations.
</p>

</div>

---

## 📊 Progress Dashboard

<!-- STATS:START -->
| 🎯 Total Solved | 🟢 Easy | 🟡 Medium | 🔴 Hard |
| :---: | :---: | :---: | :---: |
| **6** | **4** (66.7%) | **1** (16.7%) | **1** (16.7%) |
<!-- STATS:END -->

---

## 📚 Solutions Index

<!-- PROBLEMS:START -->
| # | Title | Difficulty | Category | Solution | Time | Space |
| :-: | :-- | :-: | :-- | :-: | :-: | :-: |
| `0001` | **[Two Sum](https://leetcode.com/problems/two-sum/)** | ![Easy](https://img.shields.io/badge/Easy-22c55e?style=flat-square) | `Arrays & Hashing` | [C](solutions/0001-two-sum/solution.c), [C++](solutions/0001-two-sum/solution.cpp) | `O(N)` | `O(N)` |
| `0003` | **[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)** | ![Medium](https://img.shields.io/badge/Medium-f59e0b?style=flat-square) | `Sliding Window` | [C++](solutions/0003-longest-substring-without-repeating-characters/solution.cpp) | `O(N)` | `O(min(N, M))` |
| `0004` | **[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)** | ![Hard](https://img.shields.io/badge/Hard-ef4444?style=flat-square) | `Two Pointers / Arrays` | [C++](solutions/0004-median-of-two-sorted-arrays/solution.cpp) | `O(m + n)` | `O(m + n)` |
| `0009` | **[Palindrome Number](https://leetcode.com/problems/palindrome-number/)** | ![Easy](https://img.shields.io/badge/Easy-22c55e?style=flat-square) | `Math & Logic` | [C](solutions/0009-palindrome-number/solution.c), [C++](solutions/0009-palindrome-number/solution.cpp) | `O(log10(N))` | `O(1)` |
| `0020` | **[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)** | ![Easy](https://img.shields.io/badge/Easy-22c55e?style=flat-square) | `Stack` | [C++](solutions/0020-valid-parentheses/solution.cpp) | `O(N)` | `O(N)` |
| `0125` | **[Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)** | ![Easy](https://img.shields.io/badge/Easy-22c55e?style=flat-square) | `Two Pointers` | [C](solutions/0125-valid-palindrome/solution.c), [C++](solutions/0125-valid-palindrome/solution.cpp) | `O(N)` | `O(1)` |
<!-- PROBLEMS:END -->

---

## 🗂️ Repository Structure

Each problem is organized in its own self-contained directory under [`solutions/`](solutions/):

```text
leetcode-solutions/
├── .github/
│   └── workflows/
│       └── ci.yml              # Automated compilation & README sync check
├── scripts/
│   ├── new_problem.py          # Interactive/CLI problem generator
│   └── update_readme.py        # Automated index & stats updater
├── solutions/
│   ├── 0001-two-sum/
│   │   ├── README.md           # Problem statement, approach, and complexity
│   │   ├── solution.cpp        # C++ Implementation
│   │   └── solution.c          # C Implementation
│   └── ...
├── .gitignore
├── LICENSE
└── README.md
```

---

## 🚀 Quick Start & Automation

### 1. Add a New Solution with One Command

Use the built-in generator script to automatically scaffold boilerplate code, markdown documentation, and register it in the main index:

```bash
# Interactive mode:
python3 scripts/new_problem.py

# CLI mode:
python3 scripts/new_problem.py -n 42 -t "Trapping Rain Water" -d Hard -c "Two Pointers" -l cpp
```

### 2. Automatically Update the Dashboard & Tables

Whenever you add or modify a solution, simply run:

```bash
python3 scripts/update_readme.py
```

### 3. Compile & Run Locally

Compile with modern C++ standard (`C++17`):

```bash
# Compile C++ solution
g++ -std=c++17 -Wall -Wextra solutions/0001-two-sum/solution.cpp -o solution
./solution

# Compile C solution
gcc -Wall -Wextra solutions/0001-two-sum/solution.c -o solution
./solution
```

---

## 🧠 Categories Covered

- **Arrays & Hashing**
- **Two Pointers**
- **Sliding Window**
- **Stack & Queue**
- **Binary Search**
- **Linked List**
- **Trees & Binary Search Trees**
- **Heap / Priority Queue**
- **Backtracking**
- **Graphs**
- **Dynamic Programming**
- **Greedy Algorithms**
- **Bit Manipulation & Math**

---

## 📜 License

Distributed under the [MIT License](LICENSE). Feel free to use and adapt for your own algorithmic preparation.
