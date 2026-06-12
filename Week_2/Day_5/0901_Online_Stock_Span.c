// Author : Priyanshu Verma
// LeetCode Problem No. : 901
// Online Stock Span
// Level : Medium
// link : https://leetcode.com/problems/online-stock-span/

struct pair {
    int val;
    int spanCnt;
};

typedef struct {
    struct pair *stack;
    int top;
    int capacity;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj = malloc(sizeof *obj);
    obj->stack = malloc(10000 * sizeof *(obj->stack));
    obj->top = -1;

    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;

    while (obj->top >= 0 && price >= obj->stack[obj->top].val) {
        span += (obj->stack[obj->top]).spanCnt;
        obj->top--;
    }
    obj->stack[++obj->top].val = price;
    obj->stack[obj->top].spanCnt = span;

    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);

 * stockSpannerFree(obj);
*/
