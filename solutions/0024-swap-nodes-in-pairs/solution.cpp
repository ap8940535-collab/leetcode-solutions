/**
 * Problem: 24. Swap Nodes in Pairs
 * Difficulty: Medium
 * Category: Linked List, Recursion
 * Runtime: 0 ms | Memory: 11.2 MB
 *
 * LeetCode: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode*prev = &dummy;
        while (prev-> next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = first->next;
            first->next = second->next;
            second-> next = first;
            prev->next = second;
            prev = first;
        }
        return dummy.next;
    }
};
