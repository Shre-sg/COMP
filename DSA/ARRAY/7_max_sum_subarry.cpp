#include <iostream>
using namespace std;

// print max sum of all subarrrays
// Given an array a[] of size n. Output max sum of each subarray of the given array

int main()
{
    int arr[100];

    int key, n;

    cout << "type the no of ele" << endl;
    cin >> n;

    cout << "type the ele" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // oder of n^3

    int max1sum = INT16_MIN;
    for (int i = 0; i < n; i++)
    { // prints all subarrrys
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            max1sum = max(sum, max1sum);
        }
    }
    cout << max1sum << endl;

    // sum of sub arr oder of N^2

    int max2sum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0; /// as sub arry sum is cal sum gets reset
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            max2sum = max(sum, max2sum);
        }
    }
    cout << max2sum << endl;

    // very optaminized order of N^2
    //  new arry is used to store the sums of subrayy

    int cursum[n + 1];
    cursum[0] = 0;

    for (int i = 1; i <= n; i++)
    { // this loops updates the cursum with the sum of all subarry
        cursum[i] = cursum[i - 1] + arr[i - 1];
    }

    int max3sum = INT16_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = cursum[i] - cursum[j];
            max3sum = max(sum, max3sum);
        }
    }
    cout << max3sum << endl;

    // BEST one
    // oder ofa N using Kadane lgo

    int maxsum = INT16_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum < 0)
            sum = 0;

        maxsum = max(sum, maxsum);
    }
    cout << maxsum << endl;

    // For Input:   // to slove this
    // 4
    // -10 -2 -3 -4
    // Your Code's output is:
    // 0
    // It's Correct output is:
    // -2

    //    int ans = 0 , maxi = arr[0];
    //   for(int i = 0 ; i<n ; i++) {
    //       ans +=arr[i];
    //       if(ans>maxi)
    //            maxi = ans;
    //       if(arr[i]>maxi)
    //            maxi = arr[i];
    //       if(ans<0)
    //             ans = 0;
    //   }
    //   return maxi;
}