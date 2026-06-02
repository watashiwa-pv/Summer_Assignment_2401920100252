// Author : Priyanshu Verma
// LeetCode Problem No. : 1249
// Minimum Remove To Make Valid Parantheses
// Level : Medium
// link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

char* minRemoveToMakeValid(char* s) {
    if (s == NULL)
        return NULL;

    int len = strlen(s);
    int i = len - 1, top = -1;
    int *stack = malloc(len * sizeof(int));

    while (i >= 0) {
        if (s[i] == '(' && top != -1 && s[stack[top]] == ')')
            top--;
        else if (isalpha(s[i]) == 0)
            stack[++top] = i;
        
        i--;
    }

    if (top == -1)
        return s;

    int p = 0;
    i = 0;
    while (s[i]) {
        if (top != -1 && i == stack[top]) {
            top--;
            i++;
        } else {
            s[p++] = s[i++];
        }
    }
    s[p] = '\0';
    
    free(stack);

    return s;
}
