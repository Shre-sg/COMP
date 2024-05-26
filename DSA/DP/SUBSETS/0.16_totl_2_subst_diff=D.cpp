// Part 2: Count Partitions with Given Difference

// Problem Link: Partitions with Given Difference
// Problem Description:
// We are given an array ‘ARR’ with N positive integers and an integer D. We need to count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.
// Disclaimer: Don't jump directly to the solution, try it out yourself first.
// Pre-req: Count Subsets with Sum K

// Solution :
// This question is a slight modification of the problem discussed in Count Subsets with Sum K.
// We have the following two conditions given to us.
// S1 - S2 = D   – (i)
// S1 >= S2     – (ii)
//  If we calculate the total sum of elements of the array (say totSum), we can say that,
// S1 = totSum - S2      – (iii)
// Now solving for equations (i) and (iii), we can say that
// S2 = (totSum - D)/2    – (iv)
// Therefore the question “Count Partitions with a difference D” is modified to “Count Number of subsets with sum (totSum - D)/2 ”. This is exactly what we had discussed in the article  Count Subsets with Sum K.
//
// s1 - s2 = d
//(total-s2) - s2 = d
//(total - d) = 2*s2
//(total-s)/2 = s2
//
#include <bits/stdc++.h>
using namespace std;

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

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

    vector<int> arr = {0, 0, 1};
    int k = 1;
    cout << "The number of subsets found are " << findWays(arr, k);
}