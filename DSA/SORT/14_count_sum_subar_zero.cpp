#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Zero Sum Subarrays

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum 
//equal to 0.


// Example 1:

// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0].

// Example 2:

// Input:
// n = 10
// arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4]
// [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

// Your Task:
// You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 

// Expected Time Complexity: O(n*log(n))
// Expected Auxilliary Space: O(n)



//ALGO prefix sum type
//https://youtu.be/HJWiQP5Kl-Q?si=mj6iT5dr_JOJlqMQ
class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        unordered_map<long long, int> m;
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            sum = arr[i] + sum;
            if (sum == 0) {
                count++;
            }
            if (m.find(sum) != m.end()) {
                count = count + m[sum];
            }
            m[sum]++;
        }
        return count;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<long long int> arr = {4, 2, -3, 1, 6};
    int n = arr.size();

    long long int result = solution.findSubarray(arr, n);

    cout << "Number of subarrays with sum equal to 0: " << result << endl;

    return 0;
}
