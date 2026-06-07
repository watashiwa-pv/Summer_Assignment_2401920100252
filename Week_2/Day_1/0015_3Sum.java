// Author : Priyanshu Verma
// LeetCode Problem No. : 15
// 3Sum
// Level : Medium
// link : https://leetcode.com/problems/3sum/

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(nums);

        if (nums[n-1] + nums[n-2] + nums[n-3] < 0)
            return ans;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] + nums[i+1] + nums[i+2] > 0)
                break;

            if (nums[i] + nums[n-1] + nums[n-2] < 0)
                continue;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1;
            int target = -nums[i];

            while(j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
}
