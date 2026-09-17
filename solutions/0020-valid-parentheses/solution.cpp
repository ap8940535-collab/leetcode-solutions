/**
 * Problem: 20. Valid Parentheses
 * Difficulty: Easy
 * Category: String, Stack
 * Runtime: 0 ms | Memory: 8.8 MB
 *
 * LeetCode: https://leetcode.com/problems/valid-parentheses/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s){
            // opening brackets 
            if(ch =='(' || ch =='{' || ch == '[') {
                st.push(ch);
            
            }
            else{
                if(st.empty()) {
                    return false;
                }
                if (ch ==')' && st.top() != '(') {
                    return false;
                }
                if (ch == '}' && st.top() != '{') {
                    return false;
                }
                if (ch == ']' && st.top() != '[') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
        
    }
};
