/**
 * Problem: 66. Plus One
 * Difficulty: Easy
 * Category: Array, Math
 * Runtime: 0 ms | Memory: 11.6 MB
 *
 * LeetCode: https://leetcode.com/problems/plus-one/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1; i >=0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
        
    }
};
