// Author : Priyanshu Verma
// LeetCode Problem No. : 121
// Best Time to Buy and Sell Stock
// Level : Easy
// link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(int* prices, int size) {
    int min = prices[0];
    int maxP = 0;

    for (int i = 1; i < size; i++) {
        if (prices[i] < min) {
            min = prices[i];
            continue;
        }
        
        int profit = prices[i] - min;
        if (profit > maxP)
            maxP = profit;
    }

    return maxP;
}
