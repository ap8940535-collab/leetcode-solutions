/**
 * Problem: 46. Permutations
 * Difficulty: Medium
 * Category: Array, Backtracking
 * Runtime: 2 ms | Memory: 10.9 MB
 *
 * LeetCode: https://leetcode.com/problems/permutations/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;

    void solve(vector<int>& nums, vector<int>& current, vector<bool>& used) {

        // If we have used all numbers
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // If this number is already used, skip it
            if (used[i]) {
                continue;
            }

            // Choose the number
            current.push_back(nums[i]);
            used[i] = true;

            // Choose the next number
            solve(nums, current, used);

            // Backtrack: remove the number
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, current, used);

        return result;
    }
};
