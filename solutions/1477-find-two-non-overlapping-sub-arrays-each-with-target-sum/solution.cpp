/**
 * Problem: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
 * Difficulty: Medium
 * Category: Array, Hash Table
 * Runtime: 11 ms | Memory: 88.8 MB
 *
 * LeetCode: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, 1000000000);

        int left = 0;
        int sum = 0;
        int answer = 1000000000;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int length = right - left + 1;

                if (left > 0 && best[left - 1] != 1000000000) {
                    answer = min(answer, length + best[left - 1]);
                }

                if (right == 0) {
                    best[right] = length;
                }
                else {
                    best[right] = min(best[right - 1], length);
                }
            }

            else if (right > 0) {
                best[right] = best[right - 1];
            }
        }

        if (answer == 1000000000) {
            return -1;
        }

        return answer;
    }
};
