/**
 * Problem: 29. Divide Two Integers
 * Difficulty: Medium
 * Category: Math, Bit Manipulation
 * Runtime: 0 ms | Memory: 8.6 MB
 *
 * LeetCode: https://leetcode.com/problems/divide-two-integers/
 */

#include<climits>                       
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN    && divisor == -1)
        return INT_MAX;
        bool negative =(dividend<0) ^(divisor < 0);
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long ans = 0;
        while (dvd >= dvs){
            long long temp = dvs;
            long long multiple = 1;
            while((temp<<1)<=dvd) {
                temp <<=1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }
        return negative ? -ans: ans;
        
    }
};
