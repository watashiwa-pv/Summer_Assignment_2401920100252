// Author : Priyanshu Verma
// LeetCode Problem No. : 918
// Maximum Sum Circular Subarray
// Level : Medium
// link : https://leetcode.com/problems/maximum-sum-circular-subarray/

inline int max(int a, int b)
{
    return a >= b ? a : b;
}

inline int min(int a, int b)
{
    return a <= b ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int currMax = 0, currMin = 0, total = 0;
    int maxSum = INT_MIN, minSum = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        currMax = max(currMax + nums[i], nums[i]);
        maxSum = max(currMax, maxSum);

        currMin = min(currMin + nums[i], nums[i]);
        minSum = min(currMin, minSum);

        total += nums[i];
    }

    if (maxSum < 0) return maxSum;
    return max(maxSum, total - minSum);
}
