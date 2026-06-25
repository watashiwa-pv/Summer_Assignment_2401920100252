/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode *temp = head;
    head = head->next;
    temp->next = swapPairs(head->next);
    head->next = temp;
    
    return head;
}
