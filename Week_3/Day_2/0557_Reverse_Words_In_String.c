// Author : Priyanshu Verma
// LeetCode Problem No. : 557
// Reverse Words in a String III
// Level : Easy
// link : https://leetcode.com/problems/reverse-words-in-a-string-iii/

void reverse(char *s, int b, int e)
{
    while (b < e) {
        char temp = s[b];
        s[b++] = s[e];
        s[e--] = temp;
    }
}

char* reverseWords(char* s) {
    int p = 0;
    for (int i = 0; ; i++) {
        if ((s[i] == ' ' || s[i] == '\0') && p != i) {
            reverse(s, p, i - 1);
            p = i + 1;
        }
        if (s[i] == '\0')
            break;
    }
    return s;
}
