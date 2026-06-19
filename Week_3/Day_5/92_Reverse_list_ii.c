/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    struct ListNode dummy, *prev = &dummy, *curr;
    dummy.next = head;
    
    // one node before reversal starts
    for (int i = 1; i < left; i++)
        prev = prev->next;

    // reversal starts at this node
    curr = prev->next;

    //reversal by taking node next to curr and placing it next to prev
    for (int i = 0; i < right - left; i++) {
        struct ListNode *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;   
    }

    return dummy.next;
}
