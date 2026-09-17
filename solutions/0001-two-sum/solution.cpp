/**
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Category: Arrays & Hashing
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::vector<int> result = solver.twoSum(nums, target);
    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    }
    return 0;
}
