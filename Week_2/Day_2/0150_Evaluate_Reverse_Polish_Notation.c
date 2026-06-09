// Author : Priyanshu Verma
// LeetCode Problem No. : 150
// Evaluate Reverse Polish Notation
// Level : Medium
// link : https://leetcode.com/problems/evaluate-reverse-polish-notation/

int toNum(char *str) {
    int sign = 1, i = 0;
    int num = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i]) {
        int dig = str[i] - '0';
        num = num * 10 + dig;
        i++;
    }

    return sign * num;
}

int evalRPN(char** tokens, int size) {
    int stack[size];
    int i = 0, top = -1;

    while (i < size) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            stack[++top] = toNum(tokens[i]);
        } else {
            int num2 = stack[top--];
            int num1 = stack[top--];

            switch(tokens[i][0])
            {
            case '+':
                stack[++top] = num1 + num2;
                break;
            case '-':
                stack[++top] = num1 - num2;
                break;
            case '*':
                stack[++top] = num1 * num2;
                break;
            case '/':
                stack[++top] = num1 / num2;
                break;
            }
        }

        i++;
    }

    return stack[top];
}
