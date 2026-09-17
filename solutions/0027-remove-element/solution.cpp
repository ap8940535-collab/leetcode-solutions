/**
 * Problem: 27. Remove Element
 * Difficulty: Easy
 * Category: Array, Two Pointers
 * Runtime: 0 ms | Memory: 11.6 MB
 *
 * LeetCode: https://leetcode.com/problems/remove-element/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;// position to place the next valid element
        for(int i=0; i< nums.size(); i++){
            if(nums[i] != val) {
                nums[k]=nums[i];
                k++;
            }
            
        }

        return k;
    }
};
