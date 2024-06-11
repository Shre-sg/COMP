// 1122. Relative Sort Array
// Solved
// Easy
// Topics
// Companies
// Hint
// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

// Example 1:

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
// Example 2:

// Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// Output: [22,28,8,6,17,44]

// Constraints:

// 1 <= arr1.length, arr2.length <= 1000
// 0 <= arr1[i], arr2[i] <= 1000
// All the elements of arr2 are distinct.
// Each arr2[i] is in arr1.

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> result;

        // Place elements of arr1 that are in arr2 into the result in order
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr1[j] == arr2[i])
                {
                    result.push_back(arr1[j]);
                    arr1[j] = -1; // mark as processed
                }
            }
        }

        // Sort the remaining elements in arr1
        sort(arr1.begin(), arr1.end());

        // Append the remaining elements to the result
        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] != -1)
            {
                result.push_back(arr1[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> result = solution.relativeSortArray(arr1, arr2);

    // Print the result
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

/// hash map methond
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> countMap;
        vector<int> remaining, result;
        // Initialize count map with relative order elements
        for (int i = 0; i < arr2.size(); i++)
        {
            countMap[arr2[i]] = 0;
        }
        // Count occurrences of elements in target array
        for (int i = 0; i < arr1.size(); i++)
        {
            if (countMap.find(arr1[i]) != countMap.end())
            {
                countMap[arr1[i]]++;
            }
            else
            {
                remaining.push_back(arr1[i]);
            }
        }
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        // Add elements as per relative order
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < countMap[arr2[i]]; j++)
            {
                result.push_back(arr2[i]);
            }
        }
        // Add remaining elements
        for (int i = 0; i < remaining.size(); i++)
        {
            result.push_back(remaining[i]);
        }
        return result;
    }
};