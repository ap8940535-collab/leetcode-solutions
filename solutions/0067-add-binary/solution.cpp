/**
 * Problem: 67. Add Binary
 * Difficulty: Easy
 * Category: Math, String
 * Runtime: 3 ms | Memory: 11.2 MB
 *
 * LeetCode: https://leetcode.com/problems/add-binary/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            // Take digit from a
            if (i >= 0) {
                sum = sum + (a[i] - '0');
                i--;
            }

            // Take digit from b
            if (j >= 0) {
                sum = sum + (b[j] - '0');
                j--;
            }

            // Add the current binary digit
            ans = char((sum % 2) + '0') + ans;

            // Calculate carry
            carry = sum / 2;
        }

        return ans;
    }
};
