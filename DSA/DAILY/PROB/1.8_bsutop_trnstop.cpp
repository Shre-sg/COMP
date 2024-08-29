// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// Minimum Number of Platforms Required for a Railway/Bus Station
// Last Updated : 01 Aug, 2024
// We are given two arrays that represent the arrival and departure times of trains, the task is to find the minimum number of platforms required so that no train waits.

// Examples:

// Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
// Output: 3
// Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

// Input: arr[] = {9:00, 9:40}, dep[] = {9:10, 12:00}
// Output: 1
// Explanation: Only one platform is needed.

// Returns minimum number of platforms required
int findPlatform(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n)
    {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j])
        {
            plat_needed++;
            i++;
        }

        // Else decrement count of platforms needed
        else if (arr[i] > dep[j])
        {
            plat_needed--;
            j++;
        }

        // Update result if needed
        if (plat_needed > result)
            result = plat_needed;
    }

    return result;
}

// Driver code
int main()
{

    int arr[] = {100, 300, 500};
    int dep[] = {900, 400, 600};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}
