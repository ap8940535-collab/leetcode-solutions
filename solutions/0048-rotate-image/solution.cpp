/**
 * Problem: 48. Rotate Image
 * Difficulty: Medium
 * Category: Array, Math
 * Runtime: 0 ms | Memory: 10.1 MB
 *
 * LeetCode: https://leetcode.com/problems/rotate-image/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int i, j, temp;

        // Step 1: Transpose
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {

                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i]; // multiplication of the matrix
                matrix[j][i] = temp;
            }
        }

        // Step 2: Reverse every row
        for (i = 0; i < n; i++) {

            int left = 0;
            int right = n - 1;

            while (left < right) {

                temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }
    }
};
