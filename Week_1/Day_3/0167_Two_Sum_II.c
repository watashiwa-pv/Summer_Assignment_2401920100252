// Author : Priyanshu Verma
// LeetCode Problem No. : 167
// Two Sum II - Input Array Is Sorted
// Level : Medium
// link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *ans = malloc(2 * sizeof(int));
    int i = 0, j = numbersSize - 1;
    *returnSize = 2;
    ans[0] = ans[1] = -1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            ans[0] = i + 1;
            ans[1] = j + 1;
            break;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return ans;
}
