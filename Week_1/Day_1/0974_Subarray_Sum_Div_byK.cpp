// Author : Priyanshu Verma
// LeetCode Problem No. : 974
// Subarray Sums Divisible by K
// Level : Medium
// link : https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0, sum = 0, rem = 0;
        vector<int> rems(k);
        rems[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rem = ((sum % k) + k) % k;  // +ve remainder

            cnt += rems[rem];
            rems[rem]++;
        }

        return cnt;
    }
};
