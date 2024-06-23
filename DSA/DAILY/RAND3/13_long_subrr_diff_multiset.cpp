#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>


// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109


using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms; //its a sorted set
        int longest = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            ms.insert(nums[r]);
            int largest = *ms.rbegin();  //retunrs a iterator ie derefrencing using *
            int smallest = *ms.begin();  //retunrs a iterator ie derefrencing using *
            while (abs(largest - smallest) > limit) {
                ms.erase(ms.find(nums[l]));
                l++;
                largest = *ms.rbegin();
                smallest = *ms.begin();
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    cout << "Longest subarray length: " << sol.longestSubarray(nums, limit) << endl;

    nums = {10, 1, 2, 4, 7, 2};
    limit = 5;
    cout << "Longest subarray length: " << sol.longestSubarray(nums, limit) << endl;

    nums = {4, 2, 2, 2, 4, 4, 2, 2};
    limit = 0;
    cout << "Longest subarray length: " << sol.longestSubarray(nums, limit) << endl;

    return 0;
}
