// Author : Priyanshu Verma
// LeetCode Problem No. : 40
// Combinatio Sum II
// Level : Medium
// link : https://leetcode.com/problems/combination-sum-ii/

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> track = new ArrayList<>();

        Arrays.sort(candidates);

        solve(res, track, candidates, target, 0, 0);

        return res;
    }

    private void solve(List<List<Integer>> res, List<Integer> track, int[] candidates, int target, int idx, int sum) {
        if (sum > target)
            return;

        if (sum == target) {
            res.add(new ArrayList(track));
            return;
        }

        for (int i = idx; i < candidates.length; i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            track.add(candidates[i]);
            solve(res, track, candidates, target, i + 1, sum + candidates[i]);
            track.remove(track.size() - 1);
        }
    }
}
