// Author : Priyanshu Verma
// LeetCode Problem No. : 2095
// Delete the Middle Node of a Linked List
// Level : Medium
// link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    struct ListNode **slow = &head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = &((*slow)->next);
    }

    *slow = (*slow)->next;

    return head;
}
