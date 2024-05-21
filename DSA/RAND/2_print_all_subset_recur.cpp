// 78. Subsets

// Given an integer array nums of unique elements, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

// approach
//  Final Output:
//  The subsets generated are:

// []
// [1]
// [2]
// [1, 2]
// [3]
// [1, 3]
// [2, 3]
// [1, 2, 3]
// Complete Execution Trace:
// Here's how the function calls proceed:

// generateSubsets([], 0, [])
// generateSubsets([], 1, [])
// generateSubsets([], 2, [])
// generateSubsets([], 3, []) -> Add []
// generateSubsets([3], 3, [3]) -> Add [3]
// generateSubsets([2], 2, [2])
// generateSubsets([2], 3, [2]) -> Add [2]
// generateSubsets([2, 3], 3, [2, 3]) -> Add [2, 3]
// generateSubsets([1], 1, [1])
// generateSubsets([1], 2, [1])
// generateSubsets([1], 3, [1]) -> Add [1]
// generateSubsets([1, 3], 3, [1, 3]) -> Add [1, 3]
// generateSubsets([1, 2], 2, [1, 2])
// generateSubsets([1, 2], 3, [1, 2]) -> Add [1, 2]
// generateSubsets([1, 2, 3], 3, [1, 2, 3]) -> Add [1, 2, 3]

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void generateSubsets(vector<int> &nums, int index, vector<int> &currentSubset, vector<vector<int>> &allSubsets)
    {
        // Base case: if we have considered all elements
        if (index == nums.size())
        {
            allSubsets.push_back(currentSubset);
            return;
        }

        // Not take the current element
        generateSubsets(nums, index + 1, currentSubset, allSubsets);

        // Take the current element
        currentSubset.push_back(nums[index]);
        generateSubsets(nums, index + 1, currentSubset, allSubsets);

        // Backtrack: remove the current element
        currentSubset.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> allSubsets;
        vector<int> currentSubset;
        generateSubsets(nums, 0, currentSubset, allSubsets);
        return allSubsets;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.subsets(nums);

    cout << "All subsets:" << endl;
    for (const auto &subset : result)
    {
        cout << "[";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
