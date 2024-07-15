// 122. Best Time to Buy and Sell Stock II  //infinnite buy
// Solved
// Medium
// Topics
// Companies
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int f(vector<int> &Arr, int ind, int buy, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy == 0)
        {
            profit = max(0 + f(Arr, ind + 1, 0, n, dp), -Arr[ind] + f(Arr, ind + 1, 1, n, dp));
        }
        if (buy == 1)
        {
            profit = max(0 + f(Arr, ind + 1, 1, n, dp), Arr[ind] + f(Arr, ind + 1, 0, n, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int> &Arr)
    {
        int n = Arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        if (n == 0)
        {
            return 0;
        }

        int ans = f(Arr, 0, 0, n, dp);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

// tabulation

#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1)
            { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
