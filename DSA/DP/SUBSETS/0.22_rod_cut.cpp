// Rod Cutting
// MediumAccuracy: 60.66%Submissions: 111K+Points: 4

// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: Consider 1-based indexing.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and
// 6, i.e., 5+17=22.
// Example 2:

// Input:
// N=8
// Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 24
// Explanation:
// The maximum obtainable value is
// 24 by cutting the rod into 8 pieces
// of length 1, i.e, 8*price[1]= 8*3 = 24.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 1000
// 1 ≤ Ai ≤ 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int f(int ind, int n, int price[], vector<vector<int>> &dp)
    {
        if (ind == 0)
            return n * price[0];

        if (dp[ind][n] != -1)
            return dp[ind][n];

        int notpick = 0 + f(ind - 1, n, price, dp);

        int pick = -1e9;
        int roden = ind + 1; // arry index start from 0  what rodlen suppsed to be at that indeax

        if (roden <= n)
            pick = price[ind] + f(ind, n - roden, price, dp);

        return dp[ind][n] = max(pick, notpick);
    }

    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, price, dp);
    }
};

int main()
{
    // Example usage
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int price[n];
    cout << "Enter the prices: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    Solution solution;
    int maxProfit = solution.cutRod(price, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}

// tabulation approach
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // Create a DP table
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 0; i <= n; ++i)
        {
            dp[0][i] = i * price[0]; // When the rod length is considered as 1 unit piece
        }

        for (int ind = 1; ind < n; ++ind)
        {
            for (int length = 0; length <= n; ++length)
            {
                int notPick = dp[ind - 1][length]; // Don't cut at current index
                int pick = -1e9;
                int rodLength = ind + 1; // Current piece length

                if (rodLength <= length)
                {
                    pick = price[ind] + dp[ind][length - rodLength]; // Pick the current piece
                }

                dp[ind][length] = max(notPick, pick);
            }
        }

        return dp[n - 1][n];
    }
};

int main()
{
    // Example usage
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int price[n];
    cout << "Enter the prices: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    Solution solution;
    int maxProfit = solution.cutRod(price, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
