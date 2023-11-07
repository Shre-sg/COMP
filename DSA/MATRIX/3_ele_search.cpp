#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int target,n,m;
    cin>>n>>m>>target; //n==row, m==cool, target
   
    int a[n][m];
   
    for(int i=0; i<n;i++){        //input for mat
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    }
    
    int r=0;         //starting from top right cornor == a[0][m-1]
    int c=m-1;
    bool flag;

    while(r<n && c>=0){       /// idex out of mat falls off when r>n && c<0 
        if(a[r][c]==target){   //checking
            flag =1;
        }
        if(a[r][c]<target){    //rember is if not elseif
            r++;               //move down
        }
        else
            c--;                //move left
    }

    if(flag){
        cout<<"ele is found"<<endl;
    }
    else
        cout<<"ele is not found"<<endl;
}