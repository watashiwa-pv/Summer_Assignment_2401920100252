// Author : Priyanshu Verma
// LeetCode Problem No. : 22
// Generate Parentheses
// Level : Medium
// link : https://leetcode.com/problems/generate-parentheses/

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        StringBuilder s = new StringBuilder();

        solve(res, 0, 0, n, s);

        return res;
    }

    public void solve(List<String> res, int open, int close, int size, StringBuilder s) {
        if (open + close == 2 * size) {
            res.add(s.toString());
            return;
        }

        if (open < size) {
            s.append('(');
            solve(res, open + 1, close, size, s);
            s.deleteCharAt(s.length() - 1);
        }

        if (close < open) {
            s.append(')');
            solve(res, open, close + 1, size, s);
            s.deleteCharAt(s.length() - 1);
        }
    }
}
