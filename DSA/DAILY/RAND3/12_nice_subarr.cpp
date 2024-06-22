#include <iostream>
#include <vector>

using namespace std;

// 1248. Count Number of Nice Subarrays

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.


// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

// Video Explanation: Discussing 5 Approaches

// Brute Force (O(n^3))
// Count Nice Subarrays Ending at Each Index (O(n^2))
// HashMap Based Approach (O(n) Time, O(n) Space)
// Count Array Instead of HashMap (O(n) Time, O(n) Space)
// Sliding Window Approach (O(n) Time, O(1) Space)
// Watch here: https://youtu.be/bC1aHbkrJCM

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0; // Final count of subarrays
        int cnt = 0;    // Count of valid subarrays ending at current position
        int i = 0, j = 0; // Two pointers for the sliding window

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { // If the current element is odd
                k--; // Decrement k as we have encountered an odd number
                cnt = 0; // Reset the count of valid subarrays ending at this position
            }
            
            while (k == 0) { // While we have exactly k odd numbers in the window
                if (nums[i] % 2 != 0) { // If the leftmost element of the window is odd
                    k++; // Increment k as we will remove this odd number
                }
                cnt++; // Increment count of valid subarrays ending at current position
                i++; // Move the left pointer of the window to the right
            }
            
            ansCnt += cnt; // Add the count of valid subarrays to the final answer
            j++; // Move the right pointer of the window to the right
        }

        return ansCnt; // Return the final count of subarrays with exactly k odd numbers
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    // Call the method and print the result
    int result = solution.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}
