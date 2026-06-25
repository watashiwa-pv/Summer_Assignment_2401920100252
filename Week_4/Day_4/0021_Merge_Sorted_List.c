/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head = NULL, **temp = &head;

    while(list1 != NULL || list2 != NULL){
        int val1 = (list1) ? list1->val : 101, val2 = list2 ? list2->val : 101;

        if(val1 <= val2){
            *temp = list1;
            list1 = list1->next;
        }
        else{
            *temp = list2;
            list2 = list2->next;
        }
        temp = &((*temp)->next);
    }
    return head;
}
