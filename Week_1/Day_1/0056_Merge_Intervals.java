// Author : Priyanshu Verma
// LeetCode Problem No. : 56
// Merge Intervals
// Level : Medium
// link : https://leetcode.com/problems/merge-intervals/

class Solution {
    public int[][] merge(int[][] intervals) {
        ArrayList<int[]> list = new ArrayList<>();
        
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0])
                return Integer.compare(a[1], b[1]);

            return Integer.compare(a[0], b[0]);
        });

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (end >= intervals[i][0]) {
                end = Math.max(end, intervals[i][1]);
            } else {
                list.add(new int[]{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        list.add(new int[]{start, end});

        int[][] ans = new int[list.size()][];
        for(int i = 0; i < list.size(); i++)
            ans[i] = list.get(i);

        return ans;
    }
}
