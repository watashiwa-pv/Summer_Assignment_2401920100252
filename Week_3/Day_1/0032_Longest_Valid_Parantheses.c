// Author : Priyanshu Verma
// LeetCode Problem No. : 32
// Longest Valid Parantheses
// Level : Hard
// link : https://leetcode.com/problems/longest-valid-parentheses/

int max(int a, int b)
{
    return a >= b ? a : b;
}

int longestValidParentheses(char* s) {
    int open = 0;
    int close = 0;
    int maxL = 0;
    int i;

    for (i = 0; s[i]; i++) {
        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
            maxL = max(2 * close, maxL);
        else if (close > open)
            open = close = 0;
    }

    open = close = 0;

    for (i = i - 1; i >= 0; i--) {
        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
            maxL = max(2 * close, maxL);
        else if (open > close)
            open = close = 0;
    }

    return maxL;
}
