#include <iostream>
using namespace std;

int minSwap(int arr[], int n, int k);


// Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

// Example 1:

// Input : 
// arr[ ] = {2, 1, 5, 6, 3} 
// K = 3
// Output : 
// 1
// Explanation:
// To bring elements 2, 1, 3 together,
// swap index 2 with 4 (0-based indexing),
// i.e. element arr[2] = 5 with arr[4] = 3
// such that final array will be- 
// arr[] = {2, 1, 3, 6, 5}

// Example 2:

// Input : 
// arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
// K = 6 
// Output :  
// 2 
// Explanation: 
// To bring elements 2, 5, 4 together, 
// swap index 0 with 2 (0-based indexing)
// and index 4 with 6 (0-based indexing)
// such that final array will be- 
// arr[] = {9, 7, 2, 5, 4, 7, 8}



int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << endl;
    return 0;
}

int minSwap(int arr[], int n, int k) {
    int window=0, bad=0;
        
    for(int i=0; i<n; i++){
        if(arr[i]<=k)
            window++;    //keeps count of window size ie ele which are less than or euall to target
    }
        
    for(int i=0; i<window; i++){
        if(arr[i]>k)
            bad++;    //initial bad ele0 present in window size 
    }
        
    int ans=bad;
    for(int i=0,j=window; j<n ; i++,j++){   //window moves till last ele of array
            
        if(arr[i]>k)   // i it or left most is bad ele minnu it from bad ele in window as we move
            bad--;
                
        if(arr[j]>k)  //as we move right if includweed ele is bad ele increase the bad ele in window size
            bad++;
                
        ans=min(ans,bad);  //keeps track of min small ele
    }
        
    return ans;
}
