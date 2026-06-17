// Author : Priyanshu Verma
// LeetCode Problem No. : 7
// Reverse Integer
// Level : Medium
// link : https://leetcode.com/problems/reverse-integer/

int reverse(int x){
    int num = 0;
    while (x) {
        int dig = x % 10;

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && dig > 7))
            return 0;

        if (num < INT_MIN / 10 || (num == INT_MIN / 10 && dig < -8))
            return 0;

        num = num * 10 + dig;
        x /= 10;
    }

    return num;
}
