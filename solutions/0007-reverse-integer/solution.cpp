/**
 * Problem: 7. Reverse Integer
 * Difficulty: Medium
 * Category: Math
 * Runtime: 0 ms | Memory: 8.6 MB
 *
 * LeetCode: https://leetcode.com/problems/reverse-integer/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int digit = x%10;
            x = x/10;
            //check overflow before multiplying by 10
            if (ans>INT_MAX /10 ||(ans == INT_MAX/10 && digit >7)){
                return 0;
            }
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)){
                return 0;
            }
            ans = ans * 10 + digit;

        }
        return ans;
        
    }
};
