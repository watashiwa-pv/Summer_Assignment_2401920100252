// Author : Priyanshu Verma
// LeetCode Problem No. : 1047
// Remove All Adjacent Duplicates In String
// Level : Easy
// link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

char* removeDuplicates(char* s) {
    int i = 0, top = -1;
    int len = strlen(s);

    while (i < len) {
        if (top >= 0 && s[top] == s[i])
            top--;
        else
            s[++top] = s[i];

        i++;
    }
    s[++top] = '\0';

    return s;
}
