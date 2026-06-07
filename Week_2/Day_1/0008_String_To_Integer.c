// Author : Priyanshu Verma
// LeetCode Problem No. : 8
// String to Integer (atoi)
// Level : Medium
// link : https://leetcode.com/problems/string-to-integer-atoi/

int myAtoi(char* s)
{
    int i = 0;
    int sign = 1;
    int num = 0;

    while (s[i] && s[i] == ' ')
        i++;

    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (s[i] && isdigit(s[i])) {
        int dig = s[i] - '0';

        if (sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && dig > 7)))
            return INT_MAX;

        if (sign == -1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && dig >= 8)))
            return INT_MIN;

        num = 10 * num + dig;
        i++;
    }

    return sign * num;
}
