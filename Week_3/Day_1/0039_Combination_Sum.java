// Author : Priyanshu Verma
// LeetCode Problem No. : 39
// Combinatio Sum
// Level : Medium
// link : https://leetcode.com/problems/combination-sum/

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> track = new ArrayList<>();

        Arrays.sort(candidates);

        solve(res, track, candidates, target, 0);

        return res;
    }

    public void solve(List<List<Integer>> res, List<Integer> track, int[] arr, int remain, int idx) {
        if (remain == 0) {
            res.add(new ArrayList(track));
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            if (arr[i] > remain)
                break;

            track.add(arr[i]);
            solve(res, track, arr, remain - arr[i], i);
            track.remove(track.size() - 1);
        }
    }
}
