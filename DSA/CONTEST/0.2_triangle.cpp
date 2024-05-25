#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 611. Valid Triangle Number

// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are:
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000

class Solution
{
public:
    // Triangle meaning is having three sides that satisfy the triangle inequality theorem: a + b > c
    int triangleNumber(vector<int> &nums)
    {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--)
        {
            int low = 0;
            int high = i - 1;
            while (low < high)
            {
                if (nums[low] + nums[high] > nums[i])
                {
                    count += (high - low);
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return count;
    }
};

int main()
{
    // Example usage
    vector<int> sides = {4, 6, 3, 7, 2, 9, 5};
    Solution sol;
    int triangles = sol.triangleNumber(sides);
    cout << "Number of triangles that can be formed: " << triangles << endl;
    return 0;
}
