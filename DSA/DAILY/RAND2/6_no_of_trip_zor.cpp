#include <iostream>
#include <vector>

using namespace std;

// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

// Given an array of integers arr.

// We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

// Let's define a and b as follows:

// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// Note that ^ denotes the bitwise-xor operation.

// Return the number of triplets (i, j and k) Where a == b.

// Example 1:

// Input: arr = [2,3,1,6,7]
// Output: 4
// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
// Example 2:

// Input: arr = [1,1,1,1,1]
// Output: 10

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[i] <= 108

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int xor_a = 0; // from start XOR for every subarray is 0

            for (int j = i + 1; j < arr.size(); j++)
            {
                xor_a ^= arr[j - 1]; // count last character to previous XOR
                int xor_b = 0;       // from start XOR for every subarray is 0

                for (int k = j; k < arr.size(); k++)
                {
                    xor_b ^= arr[k]; // count character before end to previous XOR

                    if (xor_a == xor_b)
                    { // if XORes are equal
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {2, 3, 1, 6, 7};
    Solution sol;
    int result = sol.countTriplets(arr);
    cout << "The number of triplets is: " << result << endl;
    return 0;
}
