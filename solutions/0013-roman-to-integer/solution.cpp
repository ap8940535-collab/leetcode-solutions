/**
 * Problem: 13. Roman to Integer
 * Difficulty: Easy
 * Category: Hash Table, Math
 * Runtime: 1 ms | Memory: 13.4 MB
 *
 * LeetCode: https://leetcode.com/problems/roman-to-integer/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int result = 0;
        for (int i = 0; i<s.length(); i++){
            //if current value is smaller than next value
            if(i<s.length()-1 && value[s[i]]<value[s[i+1]])
            {
                result -= value[s[i]];
            }
            else{
                result += value[s[i]];
            }
        }
        return result;
    }
};
