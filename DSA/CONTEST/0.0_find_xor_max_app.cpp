// 3158. Find the XOR of Numbers Which Appear Twice
// Solved
// Easy
// Companies
// Hint
// You are given an array nums, where each number in the array appears either once or twice.

// Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

// Example 1:
// Input: nums = [1,2,1,3]
// Output: 1
// Explanation:
// The only number that appears twice in nums is 1.

// Example 2:
// Input: nums = [1,2,3]
// Output: 0
// Explanation:
// No number appears twice in nums.

// Example 3:
// Input: nums = [1,2,2,1]
// Output: 3
// Explanation:

// Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        int res = 0;
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }

        for (auto num : mp)
        {
            if (num.second == 2)
                res ^= num.first;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 2}; // Example input
    int result = sol.duplicateNumbersXOR(nums);
    cout << "The duplicate number is: " << result << endl;
    return 0;
}
