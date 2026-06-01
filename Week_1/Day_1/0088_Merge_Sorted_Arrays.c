// Author : Priyanshu Verma
// LeetCode Problem No. : 88
// Merge Sorted Arrays
// Level : Easy
// link : https://leetcode.com/problems/merge-sorted-array/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = nums1Size - 1;
    m--;
    n--;

    while (m >= 0 || n >= 0) {
        int num1 = (m < 0) ? nums2[0] - 1 : nums1[m];
        int num2 = (n < 0) ? nums1[0] - 1 : nums2[n];

        if (num1 > num2) {
            nums1[p--] = num1;
            m--;
        } else {
            nums1[p--] = num2;
            n--;
        }
    }
}
