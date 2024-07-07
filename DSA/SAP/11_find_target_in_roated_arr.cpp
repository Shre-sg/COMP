#include <bits/stdc++.h>
using namespace std;

// 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104
// normal sorting works too

int searchTarget(vector<int> &nums, int target)
{
    // Initialize two pointers, left and right, at the start // and end of the array.
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // Case 1: Find target
        if (nums[mid] == target)
        {
            return mid;
        }
        // Case 2: Left half is sorted
        if (nums[mid] >= nums[left])
        {
            // If the target lies within this sorted half,// move the right pointer to mid - 1.
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            // Otherwise, move the left pointer to mid + 1.
            else
            {
                left = mid + 1;
            }
        }
        // Case 3: Right half is sorted
        else
        {
            // If the target lies within this sorted half,move the left pointer to mid + 1.
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            // Otherwise, move the right pointer to mid - 1.
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

// Driver code
int main()
{

    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = searchTarget(arr1, target1);
    cout << result1 << endl; // Output: 4

    vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int result2 = searchTarget(arr2, target2);
    cout << result2 << endl; // Output: -1

    return 0;
}
