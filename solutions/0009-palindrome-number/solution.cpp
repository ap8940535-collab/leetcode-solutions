/**
 * Problem: 9. Palindrome Number
 * Difficulty: Easy
 * Category: Math & Logic
 *
 * Time Complexity:  O(log10(N))
 * Space Complexity: O(1)
 */

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + (x % 10);
            x /= 10;
        }

        // When length is odd, middle digit doesn't matter (revertedNumber / 10)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main() {
    Solution sol;
    std::cout << "121 is palindrome: " << (sol.isPalindrome(121) ? "true" : "false") << "\n";
    std::cout << "-121 is palindrome: " << (sol.isPalindrome(-121) ? "true" : "false") << "\n";
    std::cout << "10 is palindrome: " << (sol.isPalindrome(10) ? "true" : "false") << "\n";
    return 0;
}
