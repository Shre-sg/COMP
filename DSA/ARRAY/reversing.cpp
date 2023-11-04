#include<iostream>
using namespace std;

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