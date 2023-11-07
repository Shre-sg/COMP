#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    sort(arr,arr+n);
    cout<<arr[k-1]<<endl;

    //sort(arr + 2, arr + n); //this sorts from index 2 to n-1
    // sort(arr, arr + n, greater<int>()); sort ele from greater to smallest
    //learn about pairs
}