/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* return_size, int** col_size) {
    int n = *matColSize;
    int m = matSize;
    int **ans = malloc(m * sizeof *ans);
    *col_size = malloc(m * sizeof(int));
    *return_size = matSize;

    for (int i = 0; i < m; i++) {
        ans[i] = calloc(n, sizeof *ans[i]);
        (*col_size)[i] = n;
        for (int j = 0; j < n; j++) {
            if (j + 1 < n)
                mat[i][j + 1] += mat[i][j];

            if (i > 0)
                mat[i][j] += mat[i-1][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int rl = i - k > 0 ? i - k - 1 : -1;
            int rh = i + k < m ? i + k : m - 1;
            int cl = j - k > 0 ? j - k - 1 : -1;
            int ch = j + k < n ? j + k : n - 1;
            int pre1 = 0;
            int pre2 = 0;
            int pre3 = 0;
            int pre4 = 0;

            pre4 = mat[rh][ch];
            if (rl >= 0)
                pre2 = mat[rl][ch];
        
            if (cl >= 0)
                pre3 = mat[rh][cl];

            if (rl >= 0 && cl >= 0)
                pre1 = mat[rl][cl];

            ans[i][j] = (pre4 - pre2) - (pre3 - pre1);
        }
    }

    return ans;
}
