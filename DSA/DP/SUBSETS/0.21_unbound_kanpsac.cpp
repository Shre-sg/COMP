
#include <bits/stdc++.h>
using namespace std;

// Knapsack with Duplicate Items

// Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Example 1:

// Input:
// N = 2
// W = 3
// val = {1, 1}
// wt = {2, 1}
// Output:
// 3
// Explanation:
// 1.Pick the 2nd element thrice.
// 2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
// Example 2:

// Input:
// N = 4
// W = 8
// val[] = {6, 1, 7, 7}
// wt[] = {1, 3, 4, 5}
// Output:
// 48
// Explanation:
// The optimal choice is to pick the 1st element 8 times.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val and wt as input parameters and returns the maximum possible value.

// Expected Time Complexity: O(N*W)
// Expected Auxiliary Space: O(W)

// Constraints:
// 1 ≤ N, W ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100

// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        return (W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table

    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main()
{
    vector<int> wt = {2, 4, 6};    // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10;                    // Weight capacity of the knapsack
    int n = wt.size();             // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}

// tabulation

#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}

int main()
{
    vector<int> wt = {2, 4, 6};    // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10;                    // Weight capacity of the knapsack
    int n = wt.size();             // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}
