typedef struct {
    long long *stack;
    int min;
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof *obj);
    obj->top = -1;
    obj->stack = malloc(30000 * sizeof *(obj->stack));
    obj->min = INT_MAX;

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == -1) {
        obj->stack[++(obj->top)] = val;
        obj->min = val;
    } else if (obj->min <= val) {
        obj->stack[++(obj->top)] = val;
    } else {
        obj->stack[++(obj->top)] = (long long)2 * val - obj->min;
        obj->min = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] < obj->min)
        obj->min = (long long)2 * obj->min - obj->stack[obj->top];

    (obj->top)--;
}

int minStackTop(MinStack* obj) {
    if (obj->stack[obj->top] < obj->min)
        return obj->min;

    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
