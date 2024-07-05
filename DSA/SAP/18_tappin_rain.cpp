#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of N non-negative integers representing the height of blocks.
// If width of each block is 1, compute how much water can be trapped between
// the blocks during the rainy season.

// Example 1:
// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10

// example 3
//  Input:
//  N = 4
//  arr[] = {7,4,0,9}
//  Output:
//  10s
//  Explanation:
//  Water trapped by above
//  block of height 4 is 3 units and above
//  block of height 0 is 7 units. So, the
//  total unit of water trapped is 10 units.

// Example 3:
// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int height[], int n)
    {
        // code here
        long long ans = 0;
        int left = 0;      // index moving from left
        int right = n - 1; // index moving from right
        int leftbar = 0;   // store the max left bar
        int rightbar = 0;  /// stores the max right bar

        while (left < right)
        {
            // which bar is limiting
            if (height[left] <= height[right]) /// if left index is smaller than right
            {
                if (height[left] >= leftbar) // if left max bar is less than current left index bar
                    leftbar = height[left];  // max it as max left bar

                else
                    ans += leftbar - height[left]; // calculate the answer;

                left++; /// move to left+++
            }
            else // right index is less than left bar
            {
                if (height[right] >= rightbar) // right index bar is more max rightbar
                    rightbar = height[right];  // make it max

                else
                    ans += rightbar - height[right]; // update ans

                right--; // decrement right
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    // Declare and initialize an array of integers and its size
    int height[] = {3, 0, 2, 0, 4};
    int n = sizeof(height) / sizeof(height[0]);

    // Call the function trappingWater with the object, the array and its size as arguments
    // Store the return value in a long long variable
    long long ans = obj.trappingWater(height, n);

    // Print the long long variable to the standard output
    std::cout << ans << std::endl;

    // Return 0 from the main function
    return 0;
}

// BUTEFORCE
//  C++ implementation of the approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

// Driver code
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}

// bit more optamised
// time=o(n)  and  space = o(2n)
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
    // .
    for (int i = 1; i < n - 1; i++)
    {
        int var = min(left[i - 1], right[i + 1]);
        if (var > arr[i])
        {
            water += var - arr[i];
        }
    }

    return water;
}

// Driver program
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findWater(arr, n);
    return 0;
}
