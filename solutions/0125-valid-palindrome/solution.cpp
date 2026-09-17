/**
 * Problem: 125. Valid Palindrome
 * Difficulty: Easy
 * Category: Two Pointers
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = static_cast<int>(s.length()) - 1;

        while (left < right) {
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::string s1 = "A man, a plan, a canal: Panama";
    std::string s2 = "race a car";

    std::cout << "\"" << s1 << "\": " << (sol.isPalindrome(s1) ? "true" : "false") << "\n";
    std::cout << "\"" << s2 << "\": " << (sol.isPalindrome(s2) ? "true" : "false") << "\n";
    return 0;
}
