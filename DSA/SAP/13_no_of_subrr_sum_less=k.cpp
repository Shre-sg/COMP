// CPP program to count
// subarrays having sum
// less than k.

// Number of subarrays having sum less than K
// Last Updated : 19 Oct, 2022
// Given an array of non-negative numbers and a non-negative number k, find the number of subarrays having sum less than k. We may assume that there is no overflow.

// Examples :

// Input : arr[] = {2, 5, 6}
//         K = 10
// Output : 4
// The subarrays are {2}, {5}, {6} and
// {2, 5},

// Input : arr[] = {1, 11, 2, 3, 15}
//         K = 10
// Output : 4
// {1}, {2}, {3} and {2, 3}
#include <bits/stdc++.h>
using namespace std;

// Function to find number
// of subarrays having sum
// less than k.
int countSubarrays(int arr[], int n, int k)
{
    int start = 0, end = 0, count = 0, sum = arr[0];

    while (start < n && end < n)
    {
        // If sum is less than k,move end by one position. Update count and sumaccordingly.
        if (sum < k)
        {
            end++;
            if (end >= start)
                count += end - start;

            // For last element end may become n
            if (end < n)
                sum += arr[end];
        }
        // If sum is greater than orequal to k, subtractarr[start] from sum anddecrease sliding window bymoving start by one position
        else
        {
            sum -= arr[start];
            start++;
        }
    }

    return count;
}

// Driver Code
int main()
{
    int array[] = {1, 11, 2, 3, 15};
    int k = 10;
    int size = sizeof(array) / sizeof(array[0]);
    cout << countSubarrays(array, size, k);
}
