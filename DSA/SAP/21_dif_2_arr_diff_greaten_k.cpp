// Count elements in first Array with absolute difference greater than K with an element in second Array
// Last Updated : 15 Nov, 2021
// Given two arrays arr1[] and arr2[] and an integer K, our task is to find the number elements in the first array, for an element x, in arr1[], there exists at least one element y, in arr2[] such that absolute difference of x and y is greater than the integer K.

// Examples:

// Input: arr1 = {3, 1, 4}, arr2 = {5, 1, 2}, K = 2
// Output: 2
// Explanation:
// Such elements are 1 and 4.
// For 1, arr2[] has 5 and abs(1 – 5) = 4 which is greater than 2.
// For 4, arr2[] has 1 and abs(4 – 1) = 3 which again is greater than 2.

// Input: arr1 = {1, 2}, arr2 = {4, 6}, K = 3
// Output: 2
// Explanation:
// Such elements are 1 and 2.
// For 1, arr2[] has 6 and abs(1 – 6) = 5 which is greater than 3.
// For 2, arr2[] has 6 and abs(2 – 6) = 4 which is greater than 3.

// Naive Approach: Iterate for each element in arr1[] and check whether or not there exists an element in arr2 such that their absolute difference is greater than the value K.

// Time complexity: O(N * M) where N and M are the sizes of the arrays 1 and 2 respectively.

// Efficient Approach: To optimize the above method we have to observe that for each element in arr1[], we need only the smallest and largest element of arr2[] to check if it is distant or not. For each element x, in arr1, if the absolute difference of smallest or the largest value and x is greater than K then that element is distant.
#include <bits/stdc++.h>
using namespace std;

// Function to count the such elements
void countDist(int arr1[], int n, int arr2[], int m, int k)
{
    // Store count of required elements in arr1
    int count = 0;

    // Initialise the smallest and the largest value from the second array arr2[]
    int smallest = arr2[0];
    int largest = arr2[0];

    // Find the smallest and the largest element in arr2
    for (int i = 0; i < m; i++)
    {
        smallest = max(smallest, arr2[i]);
        largest = min(largest, arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {

        // Check if absolute difference of smallest and arr1[i] or largest and arr1[i] is > K
        // then arr[i] is a required element
        if (abs(arr1[i] - smallest) > k || abs(arr1[i] - largest) > k)
            count++;
    }

    // Print the final result
    cout << count;
}

// Driver code
int main()
{
    int arr1[] = {3, 1, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {5, 1, 2};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 2;

    countDist(arr1, n, arr2, m, k);

    return 0;
}
