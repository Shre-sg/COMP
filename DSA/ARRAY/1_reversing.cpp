#include<iostream>
using namespace std;

// Given an array (or string), the task is to reverse the array/string.
// Examples : 
 

// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}

void reverse(int arr[], int first, int last){
    int temp;
    while(first<last){
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;

        first++;
        last--;
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    reverse(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}