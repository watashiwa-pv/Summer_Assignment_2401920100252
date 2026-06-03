// Author : Priyanshu Verma
// LeetCode Problem No. : 53
// Maximum Subarray
// Level : Medium
// link : https://leetcode.com/problems/maximum-subarray/

int max(int a, int b)
{
    return a >= b ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int sum = 0, maxSum = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        sum = max(sum + nums[i], nums[i]);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
