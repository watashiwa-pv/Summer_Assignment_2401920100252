/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int updateSum(struct ListNode *temp, int val1, int val2, int carry){
    int sum = val1 + val2 + carry;
    temp->val = sum % 10;
    return sum / 10;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, **temp = &head;
    int carry = 0;

    while(l1 != NULL || l2 != NULL){
        int val1 = (l1 == NULL) ? 0 : l1->val, val2 = (l2 == NULL) ? 0 : l2->val;
        *temp = calloc(1, sizeof(struct ListNode));
        carry = updateSum(*temp, val1, val2, carry);
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        temp = &((*temp)->next);
    }

    if(carry){
        *temp = calloc(1, sizeof(struct ListNode));
        (*temp)->val = carry;
    }
    return head;
}
