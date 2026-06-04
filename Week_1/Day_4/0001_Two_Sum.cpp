// Author : Priyanshu Verma
// LeetCode Problem No. : 1
// Two Sum
// Level : Easy
// link : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans(2, -1);

        for (int i = 0; i < nums.size(); i++) {
            int item = target - nums[i];
            if (mp.count(item) == 1) {
                ans[0] = mp[item];
                ans[1] = i;
                break;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};
