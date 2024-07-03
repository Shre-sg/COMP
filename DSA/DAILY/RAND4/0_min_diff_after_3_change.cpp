#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

// You are given an integer array nums.
// In one move, you can choose one element of nums and change it to any value.
// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

// Example 1:

// Input: nums = [5,3,2,4]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 2 to 3. nums becomes [5,3,3,4].
// In the second move, change 4 to 3. nums becomes [5,3,3,3].
// In the third move, change 5 to 3. nums becomes [3,3,3,3].
// After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
// Example 2:

// Input: nums = [1,5,0,10,14]
// Output: 1
// Explanation: We can make at most 3 moves.
// In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// It can be shown that there is no way to make the difference 0 in 3 moves.
// Example 3:

// Input: nums = [3,100,20]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 100 to 7. nums becomes [3,7,20].
// In the second move, change 20 to 7. nums becomes [3,7,7].
// In the third move, change 3 to 7. nums becomes [7,7,7].
// After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// easy sorting approach
class Solution
{
public:
    int diff(vector<int> &nums)
    {
        int n = nums.size();
        return min({nums[n - 1] - nums[3],   // first 3 delete
                    nums[n - 2] - nums[2],   // first 2 last 1 delete
                    nums[n - 3] - nums[1],   // first 1 last 2 delete
                    nums[n - 4] - nums[0]}); // last 3 delete
    }

    int minDifference(vector<int> &nums)
    {
        if (nums.size() <= 4)
            return 0;

        sort(nums.begin(), nums.end());
        return diff(nums);
    }
};

// optamised approach
class Solution
{
public:
    int diff(vector<int> &nums)
    {
        int n = nums.size();
        return min({nums[n - 1] - nums[3],   // first 3 delete
                    nums[n - 2] - nums[2],   // first 2 last 1 delete
                    nums[n - 3] - nums[1],   // first 1 last 2 delete
                    nums[n - 4] - nums[0]}); // last 3 delete
    }

    int heap(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> max_heap;                            // max on top
        priority_queue<int, vector<int>, greater<int>> min_heap; // min on top

        for (auto it : nums)
        {
            max_heap.push(it);
            min_heap.push(it);

            if (max_heap.size() > 4)
                max_heap.pop();

            if (min_heap.size() > 4)
                min_heap.pop();
        }

        int start = 3;
        int end = n - 4;
        while (!max_heap.empty() && !min_heap.empty())
        {
            nums[start--] = max_heap.top();
            max_heap.pop();

            nums[end++] = min_heap.top();
            min_heap.pop();
        }

        return diff(nums);
    }

    int minDifference(vector<int> &nums)
    {
        if (nums.size() <= 4)
            return 0;
        return heap(nums);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 3, 2, 4, 1, 6, 7, 8, 9, 10}; // Example input
    cout << "Minimum difference after 3 deletions: " << sol.minDifference(nums) << endl;
    return 0;
}
