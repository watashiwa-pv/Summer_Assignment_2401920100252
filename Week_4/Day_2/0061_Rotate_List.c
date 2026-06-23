/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode **slow = &head, *fast = head, *result;
    int len = 0;

    if(head == NULL || head->next == NULL) return head;

    while(fast != NULL){
        len++;
        fast = fast->next;
    }

    k = k % len;
    if(k == 0) return head;
    fast = head;

    while(k-- > 1) fast = fast->next;

    while(fast->next != NULL){
        slow = &((*slow)->next);
        fast = fast->next;
    }

    if(*slow == head) return head;
    result = *slow;
    fast->next = head;
    *slow = NULL;

    return result;
}
