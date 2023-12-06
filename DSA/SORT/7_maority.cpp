#include <bits/stdc++.h>
using namespace std;

// Given an array A of N elements. Find the majority element in the array. A majority
// element in an array A of size N is an element that appears strictly more than N/2 times 
//in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.
// Example 2:

// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.

// Your Task:
// The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1)



int majorityElement(int a[], int size)
{
    unordered_map<int,int> umap;
    
    for(int i=0;i<size;i++)
    {
        umap[a[i]]++;
    }
    
    for(auto it:umap)
    {
        if(it.second>size/2)
            return it.first;
    }
    
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << majorityElement(arr, n) << endl;
    return 0;
}
