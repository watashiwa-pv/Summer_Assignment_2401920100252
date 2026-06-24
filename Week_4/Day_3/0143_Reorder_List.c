/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *prev = NULL, *curr = head;
    while (curr) {
        struct ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void reorderList(struct ListNode* head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *head2 = reverse(slow->next);
    slow->next = NULL;

    struct ListNode *l1 = head, *l2 = head2;

    while (l2) {
        struct ListNode *next1 = l1->next;
        struct ListNode *next2 = l2->next;

        l1->next = l2;
        l2->next = next1;

        l1 = next1;
        l2 = next2;
    }
}
