#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array of N integers arr[] where each element represents the maximum length of the jump 
//that can be made forward from that element. This means if arr[i] = x, then we can jump any 
//distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). 
//If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.


// Example 1:

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to the last. 
// Example 2:

// Input :
// N = 6
// arr = {1, 4, 3, 2, 6, 7}
// Output: 2 
// Explanation: 
// First we jump from the 1st to 2nd element 
// and then jump to the last element.


int main(){
    int n;
    cin>>n;
    
    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int max_=0; //curr array vale ie jump value
    int maxrange=0;// target idex to reach in the arry(destination) 
    int jump =0; //ans total min jumps needed
        
    if(n<=1){ ///if one ele is given
        cout<<"jumps = "<<0<<endl;
        return 0;
    }
        
    for(int i=0; i<n; i++){
        
        max_ = max(max_,arr[i]+i);  ///arr[i]+i basically gives the totol index travellde by forloop
        
        if(i == maxrange){
            maxrange= max_;
            jump++;    
        }
                
        if(maxrange >= n-1){
             cout<<"jumps = "<<jump<<endl;
            return 0;
        }
    }
    return -1;

//wrong code 
        // static int i=0, count=0;
        // while(i<n){
        //     int j=arr[i];
        //     while(i<j+i){
        //         i++;
        //     }
        //    // i=i+arr[i];
        //     count++;
        // }
        // cout<< count;
}