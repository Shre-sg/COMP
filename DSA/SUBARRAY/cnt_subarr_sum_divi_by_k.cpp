// 974. Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Example 2:
// Input: nums = [5], k = 9
// Output: 0

// Constraints:
// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104

// 2️⃣ Prefix Sum with Hash Map:
// In the brute force method, we check every possible subarray in an array to see if their sums are divisible by 𝑘. This means for every starting point in the array, you calculate the sum of subarrays that start there, one by one. This leads to a lot of repeated work because you keep summing up the same numbers multiple times. The prefix sum approach helps you avoid this repeated work. Here's how:

// By keeping a running total of the numbers as you go through the array.
// Using this running total we can avoid calculating the sum of subarrays from scratch each time.
// ⚛️Implementation Steps:
// Start with an initial prefix sum of 0.
// As you go through each number in the array, update the prefix sum by adding the current number.
// Calculate the remainder of this prefix sum when divided by ( k ).
// Use the hash map to check if this remainder has been seen before:
// If it has, it means there are subarrays that sum to a multiple of ( k ), and you increase your count by how many times this remainder has been seen.
// Update the hash map to include this new remainder.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Initialize count of subarrays, prefix sum, and hash map for remainders
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1; // To handle subarrays that start from the beginning

        for (int num : nums)
        {
            // Update prefix sum
            prefixSum += num;

            // Calculate the remainder of the prefix sum divided by k
            int mod = prefixSum % k;

            // Adjust negative remainders to be positive  //imporatant
            if (mod < 0)
            {
                mod += k;
            }

            // If this remainder has been seen before, it means there are subarrays ending here that are divisible by k
            if (prefixMap.find(mod) != prefixMap.end())
            {
                count += prefixMap[mod];
                prefixMap[mod] += 1;
            }
            else
            {
                prefixMap[mod] = 1;
            }
        }

        return count; // Total number of subarrays divisible by k
    }
};

int main()
{
    // Test case
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    // Create a Solution object
    Solution solution;

    // Call the subarraysDivByK function and print the result
    int result = solution.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
