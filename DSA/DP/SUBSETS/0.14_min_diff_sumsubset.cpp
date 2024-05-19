// Partition Set Into 2 Subsets With Min Absolute Sum Diff (DP- 16)

// Problem Statement:

// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference

// Pre-req: Subset Sum equal to target, Recursion on Subsequences

// Problem Link: Partition A Set Into Two Subsets With Minimum Absolute Sum Difference

// We are given an array ‘ARR’ with N positive integers. We need to partition the array into two subsets such that the absolute difference of the sum of elements of the subsets is minimum.

// We need to return only the minimum absolute difference of the sum of elements of the two partitions.

#include <bits/stdc++.h>
using namespace std;

// Function to solve the subset sum problem with memoization
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, return true
    if (target == 0)
        return dp[ind][target] = true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);

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

// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    // Calculate the subset sum for each possible sum from 0 to the total sum
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}

// Algorithm / Intuition
// This question is a slight modification of the problem discussed in the Subset Sum equal to target.

// Before discussing the approach for this question, it is important to understand what we did in the previous question of the Subset Sum equal to the target. There we found whether or not a subset exists in an array with a given target sum. We used a dp array to get to our answer.

// We used to return dp[n-1][k] as our answer. One interesting thing that is happening is that for calculating our answer for dp[n-1][k], we are also solving multiple sub-problems and at the same time storing them as well. We will use this property to solve the question of this article.

// In this question, we need to partition the array into two subsets( say with sum S1 and S2) and we need to return the minimized absolute difference of S1 and S2. But do we need two variables for it? The answer is No. We can use a variable totSum, which stores the sum of all elements of the input array, and then we can simply say S2 = totSum - S1. Therefore we only need one variable S1.

// Now, what values can S1 take? Well, it can go anywhere from 0 (no elements in S1) to totSum( all elements in S1). If we observe the last row of the dp array which we had discussed above, it gives us the targets for which there exists a subset. We will set its column value to totSum, to find the answer from 0(smaller limit of S1) to totSum (the larger limit of S1).

// Our work is very simple, using the last row of the dp array, we will first find which all S1 values are valid. Using the valid S1 values, we will find S2 (totSum - S1). From this S1 and S2, we will find their absolute difference. We will return the minimum value of this absolute difference as our answer.

// From here we will try to find a subsequence in the array with a target as discussed in Subset Sum equal to target after generating the dp array, we will use the last row to find our answer.

// Note: Readers are highly advised to watch this video “Recursion on Subsequences” to understand how we generate subsequences using recursion.

// Steps to form the recursive solution:

// We will first form the recursive solution by the three points mentioned in Dynamic Programming Introduction.

// Step 1: Express the problem in terms of indexes.

// The array will have an index but there is one more parameter “target”. We are given the initial problem to find whether there exists in the whole array a subsequence whose sum is equal to the target.

// So, we can say that initially, we need to find(n-1, target) which means that we need to find whether there exists a subsequence in the array from index 0 to n-1, whose sum is equal to the target. Similarly, we can generalize it for any index ind as follows:

// Base Cases:

// If target == 0, it means that we have already found the subsequence from the previous steps, so we can return true.
// If ind==0, it means we are at the first element, so we need to return arr[ind]==target. If the element is equal to the target we return true else false.

// Step 2: Try out all possible choices at a given index.

// We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

// We have two choices:

// Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index element. For this, we will make a recursive call to f(ind-1,target).
// Include the current element in the subsequence: We will try to find a subsequence by considering the current index as element as part of subsequence. As we have included arr[ind], the updated target which we need to find in the rest if the array will be target - arr[ind]. Therefore, we will call f(ind-1,target-arr[ind]).
// Note: We will consider the current element in the subsequence only when the current element is less or equal to the target.

// Step 3:  Return (taken || notTaken)

// As we are looking for only one subset, if any of the one among taken or not taken returns true, we can return true from our function. Therefore, we return ‘or(||)’ of both of them.

// The final pseudocode after steps 1, 2, and 3:

// Steps to memoize a recursive solution:

// If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:

// Create a dp array of size [n][totSum+1]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. The target can take any value between ‘0’ and ‘totSum’. Therefore we take the dp array as dp[n][totSum+1]
// We initialize the dp array to -1.
// Whenever we want to find the answer of particular parameters (say f(ind,target)), we first check whether the answer is already calculated using the dp array(i.e dp[ind][target]!= -1 ). If yes, simply return the value from the dp array.
// If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[ind][target] to the solution we get.
// When we get the dp array, we will use its last row to find the absolute minimum difference of two partitions.