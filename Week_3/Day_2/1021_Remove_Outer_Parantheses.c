// Author : Priyanshu Verma
// LeetCode Problem No. : 1021
// Remove Outermost Parentheses
// Level : Easy
// link : https://leetcode.com/problems/remove-outermost-parentheses/

char* removeOuterParentheses(char* s) {
    int l = 0, r = 0;
    int open = 0;
    int p = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (open > 0)
                s[p++] = s[i];

            open++;
        } else {
            open--;
            if (open > 0)
                s[p++] = s[i];
        }
    }
    s[p] = '\0';

    return s;
}
