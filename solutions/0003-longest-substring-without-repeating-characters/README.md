# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium  
**Category:** Hash Table, String  
**Runtime:** `8 ms` | **Memory:** `19.2 MB`  
**LeetCode Link:** [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  

---

## 📌 Problem Description

Given a string `s`, find the length of the **longest** **substring** without duplicate characters.



 


Example 1:



```text

**Input:** s = "abcabcbb"
**Output:** 3
**Explanation:** The answer is "abc", with the length of 3. Note that `"bca"` and `"cab"` are also correct answers.

```

Example 2:



```text

**Input:** s = "bbbbb"
**Output:** 1
**Explanation:** The answer is "b", with the length of 1.

```

Example 3:



```text

**Input:** s = "pwwkew"
**Output:** 3
**Explanation:** The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 


**Constraints:**




	- `0 <= s.length <= 10^5`
	- `s` consists of English letters, digits, symbols and spaces.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

## 📂 Implementations

- [CPP Solution](solution.cpp)
