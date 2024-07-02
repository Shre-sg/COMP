#include <iostream>
#include <vector>
using namespace std;
// Count number of occurrences (or frequency) in a sorted array
// Last Updated : 06 May, 2024
// Given a sorted array arr[] of size N and a number X, you need to find the number of occurrences of X in given array.

// Note: Expected time complexity is O(log(n))

// Examples:

// Input: N = 7, X = 2, Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 4
// Explanation: 2 occurs 4 times in the given array.

// Input: N = 7, X = 4, arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 0
// Explanation: 4 is not present in the given array.

// IMPORTANT can be sloves int just arry or by map or by binar search
// Function to find the first occurrence of an element using binary search
int findFirstOccurrence(const vector<int> &arr, int x)
{
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Safe midpoint calculation
        if (arr[mid] == x)
        {
            result = mid;
            right = mid - 1; // search in the left half
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of an element using binary search
int findLastOccurrence(const vector<int> &arr, int x)
{
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Safe midpoint calculation
        if (arr[mid] == x)
        {
            result = mid;
            left = mid + 1; // search in the right half
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

// Function to count the number of occurrences of an element in a sorted array
int countOccurrences(const vector<int> &arr, int x)
{
    int first = findFirstOccurrence(arr, x);
    if (first == -1)
    {
        return 0; // element not found
    }
    int last = findLastOccurrence(arr, x);
    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    int count = countOccurrences(arr, x);
    cout << "Element " << x << " occurs " << count << " times in the array." << endl;

    return 0;
}
