// 123. Best Time to Buy and Sell Stock III

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// Constraints:
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getAns(vector<int> &Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
        if (ind == n || cap == 0)
            return 0;

        // If the result is already calculated, return it.
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit;

        if (buy == 0)
        { // We can buy the stock
            profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
                         -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
        }
        else
        { // We can sell the stock
            profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
                         Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
        }

        // Store and return the calculated profit.
        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // Call the recursive function to calculate maximum profit
        return getAns(prices, n, 0, 0, 2, dp);
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

/// tabulation

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &Arr, int n)
{
    // Creating a 3D DP array of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.
    // do bunch of for loop for ind,and buy [0]=0; ind=n =0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 0)
                { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                            -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1)
                { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                            Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}