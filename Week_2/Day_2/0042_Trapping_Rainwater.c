// Author : Priyanshu Verma
// LeetCode Problem No. : 42
// Trapping Rainwater
// Level : Hard
// link : https://leetcode.com/problems/trapping-rain-water/

int trap(int* height, int heightSize) {
    int maxR = 0, maxL = 0, water = 0;
    int i = 0, j = heightSize - 1;

    while (i <= j) {
        if (maxL <= maxR) {
            if (height[i] > maxL)
                maxL = height[i];
            else
                water += maxL - height[i];

            i++;
        } else {
            if (height[j] > maxR)
                maxR = height[j];
            else
                water += maxR - height[j];

            j--;
        }
    }

    return water;
}
