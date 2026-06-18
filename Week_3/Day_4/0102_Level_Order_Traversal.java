// Author : Priyanshu Verma
// LeetCode Problem No. : 102
// Binary Tree Level Order Traversal
// Level : Medium
// link : https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> level = new ArrayList<>();
        Deque<TreeNode> q = new LinkedList<>();

        if (root == null)
            return ans;

        TreeNode levelEnd = root;

        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            level.add(curr.val);

            if (curr.left != null)
                q.offer(curr.left);

            if (curr.right != null)
                q.offer(curr.right);

            if (curr == levelEnd) {
                ans.add(level);
                level = new ArrayList<>();

                if (!q.isEmpty())
                    levelEnd = q.getLast();
            }
        }

        return ans;
    }
}
