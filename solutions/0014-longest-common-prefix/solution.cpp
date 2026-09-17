/**
 * Problem: 14. Longest Common Prefix
 * Difficulty: Easy
 * Category: Array, String
 * Runtime: 0 ms | Memory: 11.8 MB
 *
 * LeetCode: https://leetcode.com/problems/longest-common-prefix/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i<strs.size(); i++){
            while
            (strs[i].find(prefix) !=0 ) {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }
        return prefix;
        
    }
};
