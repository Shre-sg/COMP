#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    //time complexitiy is high it kind uses bubblesort algo
    for(int i=n-1; i>=0; i--){
            if(arr[i]<0){
                int j=i;
                while(j<n-1){
                    if(arr[j+1]>0)
                        swap(arr[j],arr[j+1]);
                j++;
                }
                
            }
        }
}

void otpsort(int arr[],int n){
    //it oder of N it uses selection sort kindda algo
    int a[n],b[n];
    int j=0,k=0;
    
    for(int i=0; i<n;i++){
        if(arr[i]<0)
            a[j++]=arr[i]; //store all -ve ele in "a" array
        else
            b[k++]=arr[i]; //storing all+ve ele in "b" arry
    }

    //COMBING ALL ARRYAS
    for(int i=0; i<k;i++){
        arr[i]=b[i];
    }

    int p=0;
    for(int i=k;i<n;i++){
        arr[i]=a[p++];
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    otpsort(arr,n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}