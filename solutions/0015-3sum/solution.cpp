/**
 * Problem: 15. 3Sum
 * Difficulty: Medium
 * Category: Array, Two Pointers
 * Runtime: 51 ms | Memory: 29.2 MB
 *
 * LeetCode: https://leetcode.com/problems/3sum/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <n-2; i++){
            if(i>0 &&nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left] == nums[left-1])
                    left++;
                    while(left<right && nums[right] == nums[right+1])
                    right--;
                }
                else if (sum<0){
                    left++;
                
                }
                else{
                    right--;
                }
            }

        }
        return ans;
        
    }
};
