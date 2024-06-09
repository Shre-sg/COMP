// 560. Subarray Sum Equals K
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[sum] = 1;
        for (auto it : nums)
        {
            sum += it;
            int find = sum - k;
            if (mp.find(find) != mp.end())
            {
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Number of subarrays with sum " << k << ": " << solution.subarraySum(nums, k) << endl;

    nums = {23, 2, 4, 6, 7};
    k = 6;
    cout << "Number of subarrays with sum " << k << ": " << solution.subarraySum(nums, k) << endl;

    nums = {23, 2, 6, 4, 7};
    k = 6;
    cout << "Number of subarrays with sum " << k << ": " << solution.subarraySum(nums, k) << endl;

    return 0;
}
