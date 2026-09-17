# 20. Valid Parentheses

**Difficulty:** Easy  
**Category:** Stack  
**Time Complexity:** O(N)  
**Space Complexity:** O(N)  
**LeetCode Link:** [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)  

---

## 📌 Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

## 💡 Intuition & Approach

### Stack Simulation
1. Use a `std::stack<char>` to track pending opening brackets.
2. When encountering an opening bracket (`(`, `{`, `[`), push its expected closing bracket onto the stack.
3. When encountering a closing bracket:
   - If the stack is empty or the top of the stack does not match, return `false`.
   - Otherwise, pop the matching bracket.
4. After examining the entire string, the stack must be empty for the string to be valid.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(N)` — Single traversal of string length $N$.
- **Space Complexity:** `O(N)` — Stack stores at most $N$ characters in the worst case.

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
