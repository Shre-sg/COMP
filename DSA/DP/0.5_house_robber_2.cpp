#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 213. House Robber II

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

class Solution
{
public:
    // Helper function to solve the problem for a linear arrangement of houses
    int solve(int ind, vector<int> &arr, vector<int> &dp)
    {
        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        if (ind == 0)
            return arr[ind];

        int pick = arr[ind] + solve(ind - 2, arr, dp);
        int nonPick = 0 + solve(ind - 1, arr, dp);

        return dp[ind] = max(pick, nonPick);
    }

    int rob(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
            return arr[0];

        // Arrays to store two cases excluding first and last house
        vector<int> arr1(arr.begin() + 1, arr.end());
        vector<int> arr2(arr.begin(), arr.end() - 1);

        // DP arrays to store results for subproblems
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Solving the two cases
        int ans1 = solve(arr1.size() - 1, arr1, dp1);
        int ans2 = solve(arr2.size() - 1, arr2, dp2);

        return max(ans1, ans2);
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums1 = {2, 3, 2};
    cout << sol.rob(nums1) << endl; // Output: 3

    vector<int> nums2 = {1, 2, 3, 1};
    cout << sol.rob(nums2) << endl; // Output: 4

    vector<int> nums3 = {1, 2, 3};
    cout << sol.rob(nums3) << endl; // Output: 3

    return 0;
}

// tabular approach
#include <bits/stdc++.h>

using namespace std;

long long int solve(vector<int> &arr)
{
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int long long nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr)
{
    vector<int> arr1;
    vector<int> arr2;

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {

        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != n - 1)
            arr2.push_back(arr[i]);
    }

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1, ans2);
}

int main()
{

    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();
    cout << robStreet(n, arr);
}
