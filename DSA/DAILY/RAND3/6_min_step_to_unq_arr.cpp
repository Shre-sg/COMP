#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// 945. Minimum Increment to Make Array Unique
// Solved
// Medium
// Topics
// Companies
// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

// Return the minimum number of moves to make every value in nums unique.

// The test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: nums = [1,2,2]
// Output: 1
// Explanation: After 1 move, the array could be [1, 2, 3].
// Example 2:

// Input: nums = [3,2,1,2,1,7]
// Output: 6
// Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
// It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int largest = INT_MIN;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
            }
            else
            {
                res += largest - nums[i] + 1;
                largest++;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 2, 1, 7};

    int result = solution.minIncrementForUnique(nums);
    cout << "The minimum increments needed for unique elements: " << result << endl;

    return 0;
}
