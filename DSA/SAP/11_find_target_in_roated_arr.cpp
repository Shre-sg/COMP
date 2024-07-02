#include <bits/stdc++.h>
using namespace std;

// normal sorting works too

int searchTarget(vector<int> &nums, int target)
{

    // Initialize two pointers, left and right, at the start
    // and end of the array.
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

            // If the target lies within this sorted half,
            // move the right pointer to mid - 1.
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

            // If the target lies within this sorted half,
            // move the left pointer to mid + 1.
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
