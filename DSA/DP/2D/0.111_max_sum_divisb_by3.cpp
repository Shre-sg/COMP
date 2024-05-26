
// 1262. Greatest Sum Divisible by Three

// Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

// Example 1:

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
// Example 2:

// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.
// Example 3:

// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).

// Constraints:

// 1 <= nums.length <= 4 * 104
// 1 <= nums[i] <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if (i == nums.size())
        {
            if (sum % 3 == 0)
            {
                return 0;
            }
            return -1e9;
        }

        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        int pick = nums[i] + solve(i + 1, nums, (sum + nums[i]) % 3, dp); //%3 is needed because sum maybr way too high  (space limit)
        int notpick = 0 + solve(i + 1, nums, sum, dp);

        return dp[i][sum] = max(pick, notpick);
    }

    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, nums, 0, dp);
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {3, 6, 5, 1, 8};
    vector<int> nums2 = {4};
    vector<int> nums3 = {1, 2, 3, 4, 4};

    cout << "Output for nums1: " << sol.maxSumDivThree(nums1) << endl; // Output: 18
    cout << "Output for nums2: " << sol.maxSumDivThree(nums2) << endl; // Output: 0
    cout << "Output for nums3: " << sol.maxSumDivThree(nums3) << endl; // Output: 12

    return 0;
}
