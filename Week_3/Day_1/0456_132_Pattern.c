// Author : Priyanshu Verma
// LeetCode Problem No. : 456
// 132 Patter
// Level : Medium
// link : https://leetcode.com/problems/132-pattern/

bool find132pattern(int* nums, int size) {
    int stack[size];
    int min_arr[size];
    int top = -1;

    min_arr[0] = nums[0];
    for (int i = 1; i < size; i++)
        min_arr[i] = nums[i] < min_arr[i - 1] ? nums[i] : min_arr[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] <= min_arr[i])
            continue;

        while (top >= 0 && stack[top] <= min_arr[i])
            top--;

        if (top >= 0 && stack[top] < nums[i])
            return true;

        stack[++top] = nums[i];
    }
    return false;
}
