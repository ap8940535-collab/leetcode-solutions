/**
 * Problem: 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Category: Arrays / Two Pointers
 *
 * Time Complexity:  O(m + n)
 * Space Complexity: O(m + n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }
        int n = arr.size();
        if (n % 2 == 1) {
            return arr[n / 2];
        }
        else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Example 1 Output: " << sol.findMedianSortedArrays(nums1, nums2) << " (Expected: 2.0)\n";

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Example 2 Output: " << sol.findMedianSortedArrays(nums3, nums4) << " (Expected: 2.5)\n";

    return 0;
}
