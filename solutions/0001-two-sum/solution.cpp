/**
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Category: Array, Hash Table
 * Runtime: 2 ms | Memory: 14.8 MB
 *
 * LeetCode: https://leetcode.com/problems/two-sum/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        for (int i = 0; i < nums . size(); i++) {
            int needed = target - nums [i];
            if (mp.find(needed) != mp.end()){
                return
                {mp[needed], i};
            }
            mp[nums[i]] = i;
        }
        return {};
        
    }
};
