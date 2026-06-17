// Author : Priyanshu Verma
// LeetCode Problem No. : 90
// Subsets II
// Level : Medium
// link : https://leetcode.com/problems/subsets-ii/

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> track = new ArrayList<>(nums.length);

        Arrays.sort(nums);

        solve(res, nums, track, 0);
        return res;
    }

    public void solve(List<List<Integer>> res, int[] nums, List<Integer> track, int idx) {
        res.add(new ArrayList(track));
        for (int i = idx; i < nums.length; i++) {
            if (i != idx && nums[i] == nums[i - 1])
                continue;

            track.add(nums[i]);
            solve(res, nums, track, i + 1);
            track.remove(track.size() - 1);
        }
    }
}
