// Dynamic Programming: Frog Jump with k Distances (DP 4)
// In this article, we will learn about "Dynamic Programming: Frog Jump with k Distances (DP 4)"

// Problem Statement:  Frog Jump with K Distance/ Learn to write 1D DP
// This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.

// MEMORIZATION
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int ind, vector<int> &height, vector<int> &dp, int k)
{
    // Base case: If we are at the beginning (index 0), no cost is needed.
    if (ind == 0)
        return 0;

    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1)
        return dp[ind];

    int mmSteps = INT_MAX;

    // Loop to try all possible jumps from '1' to 'k'
    for (int j = 1; j <= k; j++)
    {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0)
        {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }

    // Store the minimum cost for this index in the dp array and return it.
    return dp[ind] = mmSteps;
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);                  // Initialize a memoization array to store calculated results
    return solveUtil(n - 1, height, dp, k); // Start the recursion from the last index
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);               // Initialize a memoization array for the main function
    cout << solve(n, height, k) << endl; // Print the result of the solve function
    return 0;
}

// TABULAR

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int n, vector<int> &height, vector<int> &dp, int k)
{
    dp[0] = 0;

    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);               // Initialize a memoization array for the main function
    cout << solve(n, height, k) << endl; // Print the result of the solve function
    return 0;
}
