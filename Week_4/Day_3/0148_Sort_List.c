/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = NULL, **temp = &head;

    while(list1 && list2){
        if (list1->val <= list2->val){
            *temp = list1;
            list1 = list1->next;
        }
        else{
            *temp = list2;
            list2 = list2->next;
        }
        temp = &((*temp)->next);
    }
    *temp = (list1) ? list1 : list2;

    return head;
}

struct ListNode *sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *midHead = head, *fast = head;

    while(fast && fast->next && fast->next->next){
        midHead = midHead->next;
        fast = fast->next->next;
    }

    struct ListNode* temp = midHead->next;
    midHead->next = NULL;
    midHead = temp;

    head = sortList(head);
    midHead = sortList(midHead);
    head = merge(head, midHead);
    
    return head;
}
