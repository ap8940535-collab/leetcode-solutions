# 9. Palindrome Number

**Difficulty:** Easy  
**Category:** Math & Logic  
**Time Complexity:** O(log10(N))  
**Space Complexity:** O(1)  
**LeetCode Link:** [Palindrome Number](https://leetcode.com/problems/palindrome-number/)  

---

## 📌 Problem Description

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

An integer is a palindrome when it reads the same forward and backward (e.g., `121` is a palindrome while `123` is not).

### Examples

**Example 1:**
```text
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**
```text
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

---

## 💡 Intuition & Approach

### Reversing Half the Number
1. Special cases:
   - Negative numbers cannot be palindromes (e.g., `-121`).
   - If the last digit is `0`, the first digit must also be `0` (only `0` satisfies this).
2. Reverse only the second half of the number by taking `% 10` and multiplying previous reversed sum by `10`.
3. Stop when the reversed half is greater than or equal to the remaining first half (`revertedNumber >= x`).
4. Check if `x == revertedNumber` (even length) or `x == revertedNumber / 10` (odd length).

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(log10(N))` — Dividing by 10 at each step, taking roughly half the number of digits.
- **Space Complexity:** `O(1)` — Constant extra space.

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
- [C Solution](solution.c)
