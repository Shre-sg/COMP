// 300. Longest Increasing Subsequence

// Given an integer array nums, return the length of the longest strictly increasing
// subsequence
// .

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// here dp[ind][prev]
// prev+1 is donw because we cant actually have dp[ind][-1]; ie -1 is store in 0;  is stored in 1 soon on
class Solution
{
public:
    // Recursive function to find the LIS
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp, int n)
    {
        // Base case: If we have considered all elements
        if (ind == n)
            return 0;

        // Return the already computed value
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        // Option 1: Do not take the current element
        int notake = f(ind + 1, prev, nums, dp, n);

        // Option 2: Take the current element (if valid)
        int take = -1e9;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + f(ind + 1, ind, nums, dp, n);
        }

        // Store the result in dp array and return the maximum of the two options
        return dp[ind][prev + 1] = max(take, notake);
    }

    // Function to find the length of the longest increasing subsequence
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp array initialized with -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // Call the recursive function starting from the 0th index and -1 previous index
        return f(0, -1, nums, dp, n);
    }
};

// Main function to test the Solution class
int main()
{
    // Example input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Create an instance of the Solution class
    Solution sol;

    // Call the lengthOfLIS method and print the result
    int result = sol.lengthOfLIS(nums);
    cout << "Length of the Longest Increasing Subsequence: " << result << endl;

    return 0;
}

// binary searxch not nessary
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}

int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);

    return 0;
}
