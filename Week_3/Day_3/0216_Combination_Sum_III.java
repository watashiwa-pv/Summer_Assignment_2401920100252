// Author : Priyanshu Verma
// LeetCode Problem No. : 39
// Combination Sum III
// Level : Medium
// link : https://leetcode.com/problems/combination-sum-iii/

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> track = new ArrayList<>(9);
        int[] num = {1,2,3,4,5,6,7,8,9};

        solve(res, track, num, k, n, 0, 0);

        return res;
    }

    public void solve(List<List<Integer>> res, List<Integer> track, int[] num, int k, int n, int idx, int sum) {
        if (sum > n)
            return; 
    
        if (track.size() > k)
            return;

        if (track.size() == k && sum == n) {
            res.add(new ArrayList(track));
            return;
        }

        for (int i = idx; i < num.length; i++) {
            track.add(num[i]);
            solve(res, track, num, k, n, i + 1, sum + num[i]);
            track.remove(track.size() - 1);
        }
    }
}
