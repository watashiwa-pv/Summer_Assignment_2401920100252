// Author : Priyanshu Verma
// LeetCode Problem No. : 328
// Odd Even Linked List
// Level : Medium
// link : https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode **slow = &head, *fast = head;

    while (n-- > 1)
        fast = fast->next;

    while (fast && fast->next) {
        fast = fast->next;
        slow = &((*slow)->next);
    }

    *slow = (*slow)->next;

    return head;
}
