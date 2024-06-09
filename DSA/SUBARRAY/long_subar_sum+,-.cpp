// Longest Subarray with sum K | [Postives and Negatives]

// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Examples
// Example 1:
// Input Format:
//  N = 3, k = 5, array[] = {2,3,5}
// Result:
//  2
// Explanation:
//  The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format
// : N = 3, k = 1, array[] = {-1, 1, 1}
// Result:
//  3
// Explanation:
//  The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.

// bruteforrcee

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// 2nd bruteforce

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        int s = 0;
        for (int j = i; j < n; j++)
        { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// prefixsum method

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
