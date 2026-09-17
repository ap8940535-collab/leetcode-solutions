/**
 * Problem: 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Category: Hash Table, String
 * Runtime: 8 ms | Memory: 19.2 MB
 *
 * LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int left = 0;
        int ans = 0;
        for (int right = 0;right < s.length();right++) {
            //if character was already seen.
            if(last[s[right]] >= left){
                left = last[s[right]] + 1;
            }
           // store the latest position.
           last[s[right]]=right; // current window length.
           ans = max(ans, right - left + 1);
        }
        return ans;
        
    }
};
