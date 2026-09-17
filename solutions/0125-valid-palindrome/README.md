# 125. Valid Palindrome

**Difficulty:** Easy  
**Category:** Two Pointers  
**Time Complexity:** O(N)  
**Space Complexity:** O(1)  
**LeetCode Link:** [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)  

---

## 📌 Problem Description

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

### Examples

**Example 1:**
```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

**Example 2:**
```text
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

---

## 💡 Intuition & Approach

### Two Pointers (In-Place)
1. Initialize two pointers: `left = 0` and `right = s.length() - 1`.
2. Move `left` forward until it points to an alphanumeric character.
3. Move `right` backward until it points to an alphanumeric character.
4. Compare characters case-insensitively using `tolower()`. If they mismatch, return `false`.
5. Increment `left` and decrement `right` until they meet or cross.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(N)` — Each character is visited at most twice.
- **Space Complexity:** `O(1)` — In-place verification without extra memory.

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
- [C Solution](solution.c)
