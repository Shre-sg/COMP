// 322. Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int f(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amt < 0)
            return 1e9; // Handling negative amount
        if (ind == 0)
        {
            if (amt % coins[0] == 0)
                return amt / coins[0];
            return 1e9;
        }
        if (dp[ind][amt] != -1)
            return dp[ind][amt];

        int notpick = f(ind - 1, amt, coins, dp);
        int pick = 1e9;
        if (amt >= coins[ind])
            pick = 1 + f(ind, amt - coins[ind], coins, dp);

        return dp[ind][amt] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amt)
    {
        if (amt == 0)
            return 0; // Edge case: 0 amount requires 0 coins
        if (coins.empty())
            return -1; // Edge case: no coins available

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));

        int ans = f(n - 1, amt, coins, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = solution.coinChange(coins, amount);
    if (result != -1)
        cout << "The minimum number of coins required: " << result << endl;
    else
        cout << "It's not possible to make the amount with the given coins." << endl;

    // Test case 2
    coins = {2};
    amount = 3;
    result = solution.coinChange(coins, amount);
    if (result != -1)
        cout << "The minimum number of coins required: " << result << endl;
    else
        cout << "It's not possible to make the amount with the given coins." << endl;

    return 0;
}

// tabulataion

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int> &arr, int T)
{
    int n = arr.size();

    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));

    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }

    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];

            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];

            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }

    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];

    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;

    return ans; // Return the minimum number of elements needed
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int T = 7;

    // Call the function to find the minimum number of elements needed
    int result = minimumElements(arr, T);

    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << result << endl;

    return 0; // Return 0 to indicate successful program execution
}
