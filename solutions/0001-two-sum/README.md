# 1. Two Sum

**Difficulty:** Easy  
**Category:** Arrays & Hashing  
**Time Complexity:** O(N)  
**Space Complexity:** O(N)  
**LeetCode Link:** [Two Sum](https://leetcode.com/problems/two-sum/)  

---

## 📌 Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

### Examples

**Example 1:**
```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**
```text
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

---

## 💡 Intuition & Approach

### Hash Map (One-Pass)
1. Iterate through the array while maintaining a hash map of `{value: index}`.
2. For each element `nums[i]`, compute its complement: `complement = target - nums[i]`.
3. If `complement` is already in the map, return the pair `[map[complement], i]`.
4. Otherwise, record `nums[i]` and its index into the map.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(N)` — Single pass over the array of length $N$, with $O(1)$ average hash map lookups.
- **Space Complexity:** `O(N)` — Hash map stores at most $N$ elements.

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
- [C Solution](solution.c)
