/**
 * Problem: 125. Valid Palindrome
 * Difficulty: Easy
 * Category: Two Pointers
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) {
            left++;
        }
        while (left < right && !isalnum((unsigned char)s[right])) {
            right--;
        }

        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main(void) {
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";

    printf("\"%s\": %s\n", s1, isPalindrome(s1) ? "true" : "false");
    printf("\"%s\": %s\n", s2, isPalindrome(s2) ? "true" : "false");
    return 0;
}
