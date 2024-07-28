#include <iostream>
using namespace std;

// Largest Sum Contiguous Subarray (Kadane’s Algorithm)
// Last Updated : 22 May, 2024
// Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within a arr[] with the largest sum.

// Example:

// Input: arr = {-2,-3,4,-1,-2,1,5,-3}
// Output: 7
// Explanation: The subarray {4,-1, -2, 1, 5} has the largest sum 7.

// Input: arr = {2}
// Output: 2
// Explanation: The subarray {2} has the largest sum 1.

// Input: arr = {5,4,1,7,8}
// Output: 25
// Explanation: The subarray {5,4,1,7,8} has the largest sum 25.

// kadane algo
class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxsum = -1e9;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxsum = max(sum, maxsum);

            if (sum < 0)
                sum = 0;
        }

        return maxsum;
    }
};

int main()
{
    // Example usage
    int arr[] = {1, -2, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    long long result = sol.maxSubarraySum(arr, n);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
