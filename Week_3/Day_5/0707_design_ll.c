typedef struct node {
    int val;
    struct node *next;
} Node;


typedef struct {
    Node *head;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = calloc(1, sizeof(MyLinkedList));

    obj->head = NULL;
    obj->size = 0;

    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index >= obj->size || index < 0) {
        return -1;
    } else {
        Node *temp = obj->head;

        while (temp) {
            if (!index) return temp->val;
            index--;
            temp = temp->next;
        }

        return -1;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *node = calloc(1, sizeof(Node));
    node->val = val;
    
    if (!obj->head) {
        obj->head = node;
        obj->size++;
        return;
    }

    node->next = obj->head;
    obj->head = node;

    obj->size += 1;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *node = calloc(1, sizeof(Node));
    node->val = val;

    if (!obj->head) {
        obj->head = node;
        obj->size++;
    } else {
        Node *temp = obj->head;

        while (temp->next)
            temp = temp->next;
        
        temp->next = node;
        obj->size++;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    } else if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    } else {
        Node **temp = &(obj->head), *node = calloc(1, sizeof(Node));

        while (index--)
            temp = &((*temp)->next);

        node->val = val;
        node->next = *temp;
        *temp = node;

        obj->size += 1;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (0 <= index && index < obj->size) {
        Node **temp = &(obj->head), *node;

        while (index--)
            temp = &((*temp)->next);

        node = *temp;
        *temp = (*temp)->next;
        free(node);

        obj->size -= 1;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *temp = obj->head;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
