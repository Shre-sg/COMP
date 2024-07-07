#include <bits/stdc++.h>
using namespace std;

// vector<int> arr = {3, 1, 2, 4};
// int k = 6;
// The number of subarrays is: 2

// vector<int> arr = {1, 2, 3};
// int k = 3;
// The number of subarrays is: 2

// vector<int> arr = {-1, -1, 1, 1};
// int k = 0;
// The number of subarrays is: 4

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++)
    {
        // Add current element to prefix Sum:
        preSum += arr[i];
        // Calculate x-k:
        int remove = preSum - k;
        // Check if remove is in the map and add its count to cnt:
        if (mpp.find(remove) != mpp.end())
        {
            cnt += mpp[remove];
        }
        // Update the count of prefix sum in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
