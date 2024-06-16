// 330. Patching Array
// Solved
// Hard
// Topics
// Companies
// Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

// Return the minimum number of patches required.

 

// Example 1:

// Input: nums = [1,3], n = 6
// Output: 1
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
// Example 2:

// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].
// Example 3:

// Input: nums = [1,2,2], n = 5
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// nums is sorted in ascending order.
// 1 <= n <= 231 - 1


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing = 1;
        int patches = 0;
        int index = 0;

        while (missing <= n) {
            if (index < nums.size() && nums[index] <= missing) {
                missing += nums[index];
                index++;
            } else {
                missing += missing;
                patches++;
            }
        }

        return patches;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3};
    int n1 = 6;
    cout << "Minimum patches for {1, 3} with n = 6: " << solution.minPatches(nums1, n1) << endl; // Output: 1

    // Test case 2
    vector<int> nums2 = {1, 5, 10};
    int n2 = 20;
    cout << "Minimum patches for {1, 5, 10} with n = 20: " << solution.minPatches(nums2, n2) << endl; // Output: 2

    // Test case 3
    vector<int> nums3 = {1, 2, 2};
    int n3 = 5;
    cout << "Minimum patches for {1, 2, 2} with n = 5: " << solution.minPatches(nums3, n3) << endl; // Output: 0

    // Additional test case 4
    vector<int> nums4 = {1, 2, 31, 33};
    int n4 = 2147483647;
    cout << "Minimum patches for {1, 2, 31, 33} with n = 2147483647: " << solution.minPatches(nums4, n4) << endl; // Output: 28

    return 0;
}
