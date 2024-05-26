#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 494. Target Sum

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution
{
public:
    int f(vector<int> &nums, int n, int target, int curSum)
    {
        // Base case: if we have processed all elements
        if (n == 0)
        {
            // Check if the current sum equals the target
            return (curSum == target) ? 1 : 0;
        }

        // Recursive case: include the current element as + and -
        int plus = f(nums, n - 1, target, curSum + nums[n - 1]);
        int minu = f(nums, n - 1, target, curSum - nums[n - 1]);

        return plus + minu;
    }

    int findTargetSumWays(vector<int> &nums, int sum)
    {
        // Start the recursion with the whole array, target sum, and initial sum of 0
        return f(nums, nums.size(), sum, 0);
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    int result1 = solution.findTargetSumWays(nums1, target1);
    cout << "Number of ways to achieve the target sum for test case 1: " << result1 << endl; // Output: 5

    // Test case 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int result2 = solution.findTargetSumWays(nums2, target2);
    cout << "Number of ways to achieve the target sum for test case 2: " << result2 << endl; // Output: 1

    return 0;
}

/// one more striver way is

#include <bits/stdc++.h>
using namespace std;

// Function to count partitions of the array into subsets with a given target sum
int countPartitionsUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base cases
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // Two ways to partition: include or exclude the element
        if (target == 0 || target == arr[0])
            return 1; // One way to partition: include or exclude the element
        return 0;     // No way to partition
    }

    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Calculate the number of ways without taking the current element
    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

    // Calculate the number of ways by taking the current element
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the sum of ways in the DP array and return it
    return dp[ind][target] = (notTaken + taken);
}

// Function to count the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0)
        return 0; // Not possible to achieve the target sum
    if ((totSum - target) % 2 == 1)
        return 0; // The difference between the total sum and target sum must be even

    int s2 = (totSum - target) / 2; // Calculate the required sum for each subset

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); // Initialize DP table
    return countPartitionsUtil(n - 1, s2, arr, dp);     // Call the helper function
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;

    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;

    return 0; // Return 0 to indicate successful program execution
}

// Algorithm / Intuition
// The first approach that comes to our mind is to generate all subsequences and try both options of placing ‘-’ and ‘+’ signs and count the expression if it evaluates the answer.
// This surely will give us the answer but can we try something familiar to the previous problems we have solved?

// The answer is yes! We can use the concept we studied in the following article Count Partitions with Given Difference (DP – 18).

// The following insights will help us to understand intuition better:

// If we think deeper, we can say that the given ‘target’ can be expressed as addition of two integers (say S1 and S2).
// S1 + S2 = target   – (i)

// Now, from where will this S1 and S2 come?  If we are given the array as [a,b,c,d,e], we want to place ‘+’ or ‘-’ signs in front of every array element and then add it. One example is :
// +a-b-c+d+e which can be written as (+a+d+e) + (-b-c).

// Therefore, we can say that S1=(+a+d+e) and S2=(-b-c) for this example.

//  If we calculate the total sum of elements of the array (say totSum), we can can say that,
// S1 = totSum - S2      – (ii)

// Now solving for equations (i) and (iii), we can say that
// S2 = (totSum - target)/2    – (iv)

// Therefore this question is modified to “Count Number of subsets with sum (totSum - target)/2 ”. This is exactly what we had discussed in the article  Count Subsets with Sum K.

// Edge Cases:

// The following edge cases need to be handled:

// As the array elements are positive integers including zero, we don’t want to find the case when S2 is negative or we can say that totSum is lesser than D, therefore if totSum<target, we simply return 0.
// S2 can’t be a fraction, as all elements are integers, therefore if totSum - target is odd, we can return 0.
// From here on we will discuss the approach to “Count Subsets with Sum K” with the required modifications. Moreover, as the array elements can also contain 0, we will handle it as discussed in part-1 of this article.