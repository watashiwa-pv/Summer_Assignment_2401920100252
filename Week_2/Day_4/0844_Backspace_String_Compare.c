// Author : Priyanshu Verma
// LeetCode Problem No. : 844
// Backspace String Compare
// Level : Easy
// link : https://leetcode.com/problems/backspace-string-compare/

char *processString(char *str) {
    int i = 0, top = -1;
    int len = strlen(str);

    while (i < len) {
        if (str[i] != '#')
            str[++top] = str[i];
        else if (top >= 0)
            top--;

        i++;
    }
    str[++top] = '\0';

    return str;
}

bool backspaceCompare(char* s, char* t) {
    char *stack1;
    char *stack2;

    stack1 = processString(s);
    stack2 = processString(t);

    return (strcmp(stack1, stack2) == 0);
}
