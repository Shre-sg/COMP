// Given two arrays a[] and b[] of size n and m respectively. 
//The task is to find the number of elements in the union between these two arrays.
// Input:
// 6 2 
// 85 25 1 32 54 6
// 85 2 
// Output: 
// 7
// Explanation: 
// 85, 25, 1, 32, 54, 6, and
// 2 are the elements which comes in the
// union set of both arrays. So count is 7.

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int uni(int a[],int n,int b[],int m){
  
    int c[n+m],k=0; // c is arr of combined a and b arrys
  
    for(int i=0; i<n;i++){
        c[k++]=a[i];
    }

    for(int j=0; j<m;j++){
        c[k++]=b[j];
    }

    sort(c,c+(n+m)); //sorting the array

    // for(int i=0;i<(n+m);i++){
    //     cout<<c[i]<<" ";
    // }

    int count=1;
    for(int i=0;i<(n+m);i++){       //count keeps the count of union ele by checing next numbers ie 
        if(c[i]!=c[i+1])            //counting all unique ele
            count++;
    }

    return count-1;   //count-1 because i amdoing count++ at last
}

int main(){

    int n, m;
    cin>>n>>m;

    int a[n], b[m];

    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    for(int i=0; i<m;i++){
        cin>>b[i];
    }

    int count =uni(a,n,b,m);

    cout<<endl<<count;
}