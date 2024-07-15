// 309. Best Time to Buy and Sell Stock with Cooldown

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp)
{
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind >= n)
        return 0;

    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;

    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
    }

    // Store the result in the DP array and return
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    int ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << stockProfit(prices) << endl;
    return 0;
}

// tabulation

#include <bits/stdc++.h>
using namespace std;

int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    // Create a 2D DP array with dimensions (n+2) x 2, initialized to 0
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;

            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1)
            { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};
    cout << "The maximum profit that can be generated is " << stockProfit(prices) << endl;
    return 0;
}
