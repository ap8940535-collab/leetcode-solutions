# 4. Median of Two Sorted Arrays

**Difficulty:** Hard  
**Category:** Two Pointers / Arrays  
**Time Complexity:** O(m + n)  
**Space Complexity:** O(m + n)  
**LeetCode Link:** [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)  

---

## 📌 Problem Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the **median** of the two sorted arrays.

The overall run time complexity should ideally be `O(log (m+n))`, but a linear two-pointer merge approach `O(m+n)` provides an intuitive, robust foundation.

### Examples

**Example 1:**
```text
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**
```text
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

### Constraints
- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

---

## 💡 Intuition & Approach

### Two Pointers Merge (Linear Scan)
1. Initialize two pointers, `i = 0` for `nums1` and `j = 0` for `nums2`, and an auxiliary array `arr`.
2. Compare elements at `nums1[i]` and `nums2[j]`. Append the smaller element to `arr` and advance its pointer.
3. Once one array is exhausted, append the remaining elements from the other array.
4. Calculate the total size `n = arr.size()`:
   - If `n` is **odd**, the median is the middle element: `arr[n / 2]`.
   - If `n` is **even**, the median is the average of the two middle elements: `(arr[n / 2 - 1] + arr[n / 2]) / 2.0`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** `O(m + n)` — We traverse both arrays completely once during the merge process.
- **Space Complexity:** `O(m + n)` — We store all $m + n$ merged elements in vector `arr`.

---

## 📂 Implementations

- [C++ Solution](solution.cpp)
