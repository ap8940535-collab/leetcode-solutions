# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium  
**Category:** Sliding Window  
**Time Complexity:** O(N)  
**Space Complexity:** O(min(N, M))  
**LeetCode Link:** [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  

---

## 📌 Problem Description

Given a string `s`, find the length of the **longest substring** without repeating characters.

### Examples

**Example 1:**
```text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**
```text
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**
```text
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
```

---

## 💡 Intuition & Approach

### Optimized Sliding Window
1. Use an array or hash map `last_seen` to track the most recent index of each character.
2. Maintain a window `[left, right]`.
3. If the current character `s[right]` was seen at or after index `left`, advance `left` to `last_seen[s[right]] + 1`.
4. Update `last_seen[s[right]] = right`.
5. Maximize `max_len = max(max_len, right - left + 1)`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(N)` — Single pass over string length $N$.
- **Space Complexity:** `O(min(N, M))` — Where $M$ is the size of the character set (at most 128 for ASCII).

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
