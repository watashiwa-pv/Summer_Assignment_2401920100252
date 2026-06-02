// Author : Priyanshu Verma
// LeetCode Problem No. : 523
// Continuous Subarray Sum
// Level : Medium
// link : https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }

        return false;
    }
};
