/**
 * Problem: 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Category: Array, Binary Search
 * Runtime: 0 ms | Memory: 95.8 MB
 *
 * LeetCode: https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i =0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1 [i] < nums2 [j]){
                arr.push_back(nums1 [i]);
                i++;

            }
            else {
                arr.push_back(nums2 [j]);
                j++;
            
            }
        }
        while  (i< nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }
        while (j< nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }
        int n = arr.size();
        if (n % 2 == 1){
            return arr [n/2];
        }
        else {
            return (arr[n/2 - 1] + arr[n/2])/2.0;
        }
        
    }
};
