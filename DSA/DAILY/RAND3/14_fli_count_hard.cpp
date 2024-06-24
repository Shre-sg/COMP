// 995. Minimum Number of K Consecutive Bit Flips
// Solved
// Hard
// Topics
// Companies
// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [0,1,0], k = 1
// Output: 2
// Explanation: Flip nums[0], then flip nums[2].
// Example 2:

// Input: nums = [1,1,0], k = 2
// Output: -1
// Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
// Example 3:

// Input: nums = [0,0,0,1,0,1,1,0], k = 3
// Output: 3
// Explanation: 
// Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
// Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
// Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= k <= nums.length

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int res = 0;
        vector<bool> fippp(n, false);
        int countflip = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k && fippp[i - k] == true) { // window before is flipped it doesn't affect the current index, ie reducing flip
                countflip--;
            }

            if (countflip % 2 == nums[i]) {
                // this happens
                // nums[i] = 0 flipcount % 2 = 0
                // nums[1] = 1 flipcount % 2 = 1
                if (i + k > n) {
                    return -1;
                }
                countflip++;
                fippp[i] = true;
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    int k = 3;
    int result = sol.minKBitFlips(nums, k);
    cout << "Result: " << result << endl; // Expected output: 3
    return 0;
}
