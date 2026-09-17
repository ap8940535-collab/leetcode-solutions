/**
 * Problem: 3483. Unique 3-Digit Even Numbers
 * Difficulty: Easy
 * Category: Array, Hash Table
 * Runtime: 14 ms | Memory: 31 MB
 *
 * LeetCode: https://leetcode.com/problems/unique-3-digit-even-numbers/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> numbers;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    if (digits[i] == 0)
                        continue;

                    if (i == j || i == k || j == k)
                        continue;

                    if (digits[k] % 2 != 0)
                        continue;

                
                    int number = digits[i] * 100
                               + digits[j] * 10
                               + digits[k];

                    numbers.insert(number);
                }
            }
        }

        return numbers.size();
    }
};
