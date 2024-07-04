#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 532. K-diff Pairs in an Array

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Example 1:

// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// Example 3:

// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

// Constraints:

// 1 <= nums.length <= 104
// -107 <= nums[i] <= 107
// 0 <= k <= 107

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> a;
        for (int i : nums)
            a[i]++;

        int ans = 0;
        for (auto x : a) /// for loop for map ele is good as it removes the douplecates in array
        {
            if (k == 0)
            {
                if (x.second > 1)
                    ans++;
            }
            else if (a.find(x.first + k) != a.end())
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int k;

    // Test case 1
    nums = {1, 2, 3, 4, 5};
    k = 2;
    cout << "Number of pairs with difference " << k << ": " << solution.findPairs(nums, k) << endl; // Output: 3

    // Test case 2
    nums = {1, 3, 1, 5, 4};
    k = 0;
    cout << "Number of pairs with difference " << k << ": " << solution.findPairs(nums, k) << endl; // Output: 1

    // Test case 3
    nums = {1, 1, 1, 1, 1};
    k = 0;
    cout << "Number of pairs with difference " << k << ": " << solution.findPairs(nums, k) << endl; // Output: 1

    return 0;
}
