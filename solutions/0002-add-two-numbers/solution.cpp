/**
 * Problem: 2. Add Two Numbers
 * Difficulty: Medium
 * Category: Linked List, Math
 * Runtime: 3 ms | Memory: 77.1 MB
 *
 * LeetCode: https://leetcode.com/problems/add-two-numbers/
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while (a != nullptr || b != nullptr || carry  != 0) {
            int sum = carry;
            if (a != nullptr) {
                sum += a->val;
                a = a->next;
            }
            if ( b != nullptr){
                sum +=b->val;
                b = b->next;
            }
            carry = sum/10;
            int digit = sum % 10;
            current->next = new ListNode(digit);
            current = current->next;
    }
    return dummy->next;
    }
};
