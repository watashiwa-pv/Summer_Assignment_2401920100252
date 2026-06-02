// Author : Priyanshu Verma
// LeetCode Problem No. : 198
// House Robber
// Level : Medium
// link : https://leetcode.com/problems/house-robber/

int solve(int *, int *, int);
int max(int, int);

int rob(int* nums, int size)
{
    int dp[size];

    for (int i = 0; i < size; i++)
        dp[i] = -1;

    return max(solve(nums, dp, size - 1), solve(nums, dp, size - 2));
}

int solve(int *nums, int *dp, int n)
{
    if (n < 0) return 0;
    if (n == 0 || n == 1)
        return dp[n] = nums[n];

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = nums[n] + max(solve(nums, dp, n - 2), solve(nums, dp, n - 3));
}

int max(int a, int b)
{
    return a >= b ? a : b;
}
