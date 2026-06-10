// Author : Priyanshu Verma
// LeetCode Problem No. : 921
// Minimum Add to Make Parentheses Valid
// Level : Medium
// link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

int minAddToMakeValid(char* s) {
    int i = 0;
    int top = -1;

    while (s[i]) {
        if (top >= 0 && s[i] == ')' && s[top] == '(')
            top--;
        else
            s[++top] = s[i];

        i++;
    }
    s[++top] = '\0';

    return strlen(s);
}
