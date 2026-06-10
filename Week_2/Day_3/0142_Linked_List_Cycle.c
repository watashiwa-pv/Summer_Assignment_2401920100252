// Author : Priyanshu Verma
// LeetCode Problem No. : 142
// Linked List Cycle II
// Level : Medium
// link : https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return NULL;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}
