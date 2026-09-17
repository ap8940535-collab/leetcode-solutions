/**
 * Problem: 9. Palindrome Number
 * Difficulty: Easy
 * Category: Math & Logic
 *
 * Time Complexity:  O(log10(N))
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + (x % 10);
        x /= 10;
    }

    return (x == revertedNumber) || (x == revertedNumber / 10);
}

int main(void) {
    printf("121: %s\n", isPalindrome(121) ? "true" : "false");
    printf("-121: %s\n", isPalindrome(-121) ? "true" : "false");
    printf("10: %s\n", isPalindrome(10) ? "true" : "false");
    return 0;
}
