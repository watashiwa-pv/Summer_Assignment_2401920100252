// Author : Priyanshu Verma
// LeetCode Problem No. : 735
// Asteroid Collsion
// Level : Medium
// link : https://leetcode.com/problems/asteroid-collision/

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int *stack = malloc(asteroidsSize * sizeof(*stack));
    int *ans;
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++) {
        int val = abs(asteroids[i]);
        int alive = 1;

        while (alive && top >= 0 && stack[top] > 0 && asteroids[i] < 0) {
            if (stack[top] < val) {
                top--;
            } else if (stack[top] == val) {
                top--;
                alive = 0;
            } else {
                alive = 0;
            }
        }

        if (alive)
            stack[++top] = asteroids[i];
    }
    *returnSize = top + 1;

    ans = malloc(*returnSize * sizeof(*ans));
    for (int i = 0; i < *returnSize; i++)
        ans[i] = stack[i];

    free(stack);

    return ans;
}
