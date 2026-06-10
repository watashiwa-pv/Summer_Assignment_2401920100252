// Author : Priyanshu Verma
// LeetCode Problem No. : 430
// Flatten a Multilevel Doubly Linked List
// Level : Medium
// link : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        helper(temp);

        return head;
    }

    void helper(Node*& head) {
        if (head == nullptr)
            return;

        Node* next = nullptr; Node* prev = nullptr;
        while (head != nullptr) {
            next = head->next;
            if (head->child != nullptr) {
                head->next = head->child;
                head->child = nullptr;
                head->next->prev = head;
                head = head->next;
                helper(head);
                head->next = next;

                if (next != nullptr)
                    next->prev = head;
            }

            prev = head;
            head = next;
        }
        head = prev;
    }
};
