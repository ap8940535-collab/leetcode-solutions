/**
 * Problem: 38. Count and Say
 * Difficulty: Medium
 * Category: String
 * Runtime: 0 ms | Memory: 10 MB
 *
 * LeetCode: https://leetcode.com/problems/count-and-say/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i=2; i<=n; i++) {
            string temp = "";
            int count = 1;
            for(int j= 1; j<=ans.size(); j++){
                if(j < ans.size() && ans[j] == ans[j-1]){
                    count++;
                } else {
                   temp += to_string(count);
                   temp += ans[j-1];
                   count = 1;
                    
                                    }
            }
            ans = temp;
        }
        return ans;
        
    }
};
