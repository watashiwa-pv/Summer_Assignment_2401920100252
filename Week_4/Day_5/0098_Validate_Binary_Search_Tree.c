/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode* treenode_ptr;
bool validate(treenode_ptr root, treenode_ptr upper, treenode_ptr lower) {
    if (!root)
        return true;

    if (upper && root->val >= upper->val)
        return false;

    if (lower && root->val <= lower->val)
        return false;

    return validate(root->left, root, lower) && validate(root->right, upper, root);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, NULL, NULL);
}
