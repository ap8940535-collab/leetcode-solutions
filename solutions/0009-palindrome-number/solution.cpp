/**
 * Problem: 9. Palindrome Number
 * Difficulty: Easy
 * Category: Math
 * Runtime: 0 ms | Memory: 8.6 MB
 *
 * LeetCode: https://leetcode.com/problems/palindrome-number/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        //Negative numbera are not palindromes
        if(x<0) return false;
        int original = x;
        long long reverse = 0;
        while (x>0){
            int digit = x%10; //get last digit
            reverse = reverse * 10 + digit; //Add digit to reverse
            x = x/10; //Remove last digit
        }
        return original == reverse;
        
    }
};
