#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//impressive code
void sort012(int a[], int n)
    {
        int c0=0,c1=0,c2=0; 
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            c0++;
            else if(a[i]==1)
            c1++;
            else
            c2++;
        }
        int i=0;
        while(i<c0)
        {
            a[i]=0;
            i++;
        }
         while(i<(c0+c1))
        {
            a[i]=1;
            i++;
        }
         while(i<(c0+c1+c2))
        {
            a[i]=2;
            i++;
        }
    }

void sort(int arr[]){
    if(arr[0]==0)
    {
        if(arr[1]==1)
            return;
        else
            swap(arr[1],arr[2]);
    }
    else if(arr[0]==1){
        swap(arr[0],arr[1]);
        
        if(arr[0]<arr[2])
            return;
        else
         swap(arr[0],arr[2]);
    }
    else{
        swap(arr[0],arr[2]);
        
        if(arr[0]<arr[1])
            return;
        else
            swap(arr[0],arr[1]);
    }
}



int main(){

    //int arr[3]={1,2,0};
    //sort(arr);

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    sort012(arr,n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }

}