/**
 * Problem: 31. Next Permutation
 * Difficulty: Medium
 * Category: Array, Two Pointers
 * Runtime: 0 ms | Memory: 15.9 MB
 *
 * LeetCode: https://leetcode.com/problems/next-permutation/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int i;
        int j;
        int temp;

        // Step 1: Find the first number from the right
        // which is smaller than the number after it

        i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If we found such a number
        if (i >= 0) {

            // Find the smallest number from the right
            // which is greater than nums[i]

            j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap nums[i] and nums[j]

            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        // Step 3: Reverse everything after i

        j = n - 1;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }
};
