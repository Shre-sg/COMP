// Partition Equal Subset Sum (DP- 15)

// Problem Link: Partition Equal Subset Sum

// We are given an array ‘ARR’ with N positive integers. We need to find if we can partition the array into two subsets such that the sum of elements of each subset is equal to the other.

// If we can partition, return true else return false.

// Algorithm / Intuition
// This question is a slight modification of the problem discussed in Subset-sum equal to target. We need to partition the array(say S) into two subsets(say S1 and S2). According to the question:

// Sum of elements of S1 + sum of elements of S2 = sum of elements of S.
// Sum of elements of S1 = sum of elements of S2.
// These two conditions imply that S1 = S2 = (S/2).

// Now,

// If S (sum of elements of the input array) is odd , there is no way we can divide it into two equal halves, so we can simply return false.
// If S is even, then we need to find a subsequence in the input array whose sum is equal to S/2 because if we find one subsequence with sum S/2, the remaining elements sum will be automatically S/2. So, we can partition the given array. Hence we return true.
// Note: Readers are highly advised to watch this video “Recursion on Subsequences” to understand how we generate subsequences using recursion.

// From here we will try to find a subsequence in the array with target = S/2 as discussed in Subset-sum equal to the target

// Steps to form the recursive solution:

// We will first form the recursive solution by the three points mentioned in the Dynamic Programming Introduction.

#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to partition the array into two subsets with equal sum
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid partition
    if (target == 0)
        return true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return arr[0] == target;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken || taken;
}

// Function to check if the array can be partitioned into two equal subsets
bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else
    {
        int k = totSum / 2;

        // Create a DP table with dimensions n x k+1 and initialize with -1
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Call the subsetSumUtil function to check if it's possible to partition
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}
