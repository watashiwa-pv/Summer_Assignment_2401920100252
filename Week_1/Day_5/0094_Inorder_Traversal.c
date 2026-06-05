void traverse(struct TreeNode *root, int *ans, int *idx)
{
    if (root == NULL)
        return;

    traverse(root->left, ans, idx);
    ans[(*idx)++] = root->val;
    traverse(root->right, ans, idx); 
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = malloc(100 * sizeof(int));

    *returnSize = 0;
    traverse(root, ans, returnSize);

    return ans;
}
