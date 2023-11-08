#include<iostream>
#include <bits/stdc++.h>
using namespace std;

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