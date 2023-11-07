// Given an array, rotate the array by one position in clock-wise direction.
// Input:
// N = 5
// A[] = {1, 2, 3, 4, 5}
// Output:
// 5 1 2 3 4


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp=arr[n-1];           //storing last ele in temp
    for(int i=n-1; i>0; i--){  //shifting all ele to right
        arr[i]=arr[i-1];
    }
    arr[0]=temp;  //resinging temp to 0th ele 
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    rotate(arr,n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}