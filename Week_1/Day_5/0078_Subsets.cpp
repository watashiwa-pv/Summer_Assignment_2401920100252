class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        int idx = 0;
        solve(ans, nums, temp, idx);

        return ans;
    }

    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int idx)
    {
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(ans, nums, temp, i + 1);
            temp.pop_back();
        }
    }
};
