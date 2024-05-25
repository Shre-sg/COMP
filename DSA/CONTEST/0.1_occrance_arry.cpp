#include <iostream>
#include <vector>

using namespace std;

// 3159. Find Occurrences of an Element in an Array

// You are given an integer array nums, an integer array queries, and an integer x.

// For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

// Return an integer array answer containing the answers to all queries.

// Example 1:

// Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

// Output: [0,-1,2,-1]

// Explanation:

// For the 1st query, the first occurrence of 1 is at index 0.
// For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
// For the 3rd query, the second occurrence of 1 is at index 2.
// For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
// Example 2:

// Input: nums = [1,2,3], queries = [10], x = 5

// Output: [-1]

// Explanation:

// For the 1st query, 5 doesn't exist in nums, so the answer is -1.

// Constraints:

// 1 <= nums.length, queries.length <= 105
// 1 <= queries[i] <= 105
// 1 <= nums[i], x <= 104

class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {
        vector<int> indices;
        vector<int> result;

        // Find indices of occurrences of x in nums
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == x)
            {
                indices.push_back(i);
            }
        }

        // Map queries to indices
        for (int query : queries)
        {
            if (query <= indices.size())
            {
                result.push_back(indices[query - 1]);
            }
            else
            {
                result.push_back(-1);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 4, 2, 5}; // Example nums vector
    vector<int> queries = {1, 2, 3};          // Example queries vector
    int x = 2;                                // Example value of x
    vector<int> result = sol.occurrencesOfElement(nums, queries, x);

    // Print the result
    cout << "Indices of occurrences of " << x << " corresponding to queries: ";
    for (int idx : result)
    {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
