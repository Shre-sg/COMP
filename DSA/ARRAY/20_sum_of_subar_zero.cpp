#include <iostream>
#include <unordered_set>

using namespace std;

// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

// Example 1:
// Input:
// 5
// 4 2 -3 1 6
// Output: 
// Yes
// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

// Example 2:
// Input:
// 5
// 4 2 0 1 6
// Output: 
// Yes
// Explanation: 
// 0 is one of the element 
// in the array so there exist a 
// subarray with sum 0.


bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s{0};  //it is unordered map without the freq  and intialised with sum 0 in side
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (s.find(sum) == s.end())
            s.insert(sum);
        else
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum" << endl;
    else
        cout << "No subarray with 0 sum" << endl;

    return 0;
}
