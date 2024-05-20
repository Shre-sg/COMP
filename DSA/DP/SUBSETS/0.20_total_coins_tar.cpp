#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 518. Coin Change II

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1

class Solution
{
public:
    int f(vector<int> &arr, int ind, int T, vector<vector<long>> &dp)
    {

        if (ind == 0)
        {
            return (T % arr[0] == 0);
        }

        if (dp[ind][T] != -1)
            return dp[ind][T];

        // Calculate the number of ways without taking the current element
        int notTaken = f(arr, ind - 1, T, dp);

        // Calculate the number of ways by taking the current element
        int taken = 0;
        if (arr[ind] <= T)
            taken = f(arr, ind, T - arr[ind], dp);

        return dp[ind][T] = notTaken + taken;
    }

    int change(int T, vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<long>> dp(n, vector<long>(T + 1, -1));
        return f(arr, n - 1, T, dp);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    Solution sol;
    cout << "The total number of ways is " << sol.change(target, arr) << endl;

    return 0; // Return 0 to indicate successful program execution
}
