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

    sort(arr,arr+n);
    cout<<"smallest"<<" "<< arr[0]<<endl;
    cout<<"greatest"<<" "<< arr[n-1]<<endl;
    //sort(arr + 2, arr + n); //this sorts from index 2 to n-1
    // sort(arr, arr + n, greater<int>()); sort ele from greater to smallest
    //learn about pairs
}