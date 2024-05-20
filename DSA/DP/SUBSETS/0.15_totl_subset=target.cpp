
#include <bits/stdc++.h>
using namespace std;

// Count Subsets with Sum K (DP - 17)
// Problem Statement: Count Subsets with Sum K
// Pre-req: Subset Sum equal to target, Recursion on Subsequences
// Problem Link: Count Subsets With Sum K
// We are given an array ‘ARR’ with N positive integers and an integer K. We need to find the number of subsets whose sum is equal to K.

// Function to count the number of subsets with a given sum
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid subset
    if (target == 0)
        return 1;

    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int> &num, int k)
{
    int n = num.size();

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // Initialize the first row based on the first element of the array
    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}
