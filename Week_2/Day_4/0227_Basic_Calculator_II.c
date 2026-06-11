// Author : Priyanshu Verma
// LeetCode Problem No. : 227
// Basic Calculator II
// Level : Medium
// link : https://leetcode.com/problems/basic-calculator-ii/

int calculate(char* s) {
    int ans = 0;
    int prevNum = 0;
    int num = 0;
    char op = '+';

    for (int i = 0; ; i++) {
        char c = s[i];

        if (isdigit(c))
            num = num * 10 + (c - '0');

        if ((!isdigit(c) && c != ' ') || c == '\0') {
            switch (op) {
            case '+':
                ans += prevNum;
                prevNum = num;
                break;

            case '-':
                ans += prevNum;
                prevNum = -num;
                break;

            case '*':
                prevNum *= num;
                break;

            case '/':
                prevNum /= num;
                break;
            }

            if (c == '\0')
                break;

            op = c;
            num = 0;
        }
    }

    return ans + prevNum;
}
