/**
 * Problem: 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Category: Sliding Window
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(min(N, M))
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> last_seen(128, -1);
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            if (last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    std::cout << "\"abcabcbb\": " << sol.lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)\n";
    std::cout << "\"bbbbb\": " << sol.lengthOfLongestSubstring("bbbbb") << " (Expected: 1)\n";
    std::cout << "\"pwwkew\": " << sol.lengthOfLongestSubstring("pwwkew") << " (Expected: 3)\n";
    return 0;
}
