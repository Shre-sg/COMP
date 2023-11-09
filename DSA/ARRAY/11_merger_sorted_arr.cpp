#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Example 1:

// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9


void merge(int arr1[], int  arr2[], int n, int m) {
    
    int i =n-1, j=0;
    while(i >= 0 && j<m) {
        if(arr1[i] > arr2[j]) {
            swap(arr1[i],arr2[j]);
            j++;
        }
        else {

            i--;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

}

int main(){
    int n,m;
    cin>>n>>m;

    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    merge(arr1,arr2,n,m);
    
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
        
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
}
