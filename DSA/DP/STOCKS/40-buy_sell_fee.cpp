// 714. Best Time to Buy and Sell Stock with Transaction Fee

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

// Example 1:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

// Constraints:

// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104

#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> &Arr, int ind, int buy, int n, int fee, vector<vector<int>> &dp)
{
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind == n)
        return 0;

    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;

    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, fee, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, fee, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, fee, dp), Arr[ind] - fee + getAns(Arr, ind + 1, 0, n, fee, dp));
    }

    // Store the computed profit in the DP array
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, vector<int> &Arr)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));

    if (n == 0)
        return 0; // Edge case: No stocks to trade.

    int ans = getAns(Arr, 0, 0, n, fee, dp);
    return ans;
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}
