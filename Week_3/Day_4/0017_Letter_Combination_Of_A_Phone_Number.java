// Author : Priyanshu Verma
// LeetCode Problem No. : 17
// Letter Combinations of a Phone Number
// Level : Medium
// link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    private String[] alph = {
        null, null,
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        StringBuilder track = new StringBuilder();

        solve(ans, digits, track, 0);

        return ans;
    }

    private void solve(List<String> ans, String digits, StringBuilder track, int idx) {
        if (idx == digits.length()) {
            ans.add(track.toString());
            return;
        }

        int i = digits.charAt(idx) - '0';
        for (int j = 0; j < alph[i].length(); j++) {
            char ch = alph[i].charAt(j);
            track.append(ch);
            solve(ans, digits, track, idx + 1);
            track.deleteCharAt(track.length() - 1);
        }
    }
}
