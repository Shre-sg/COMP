#include<iostream>
using namespace std;

int search(int arr[], int key ,int n){
    int start=0, mid, last;
    last=n;

    while (start<=n)
    {
        mid=(start+last)/2;
        
        if(key == arr[mid])
            return mid;
        
        else if(key<arr[mid])
            last=mid-1;

        else
            start=mid+1;  
    }
    return -1;
    
}

int main(){
    int arr[100];

    int key, n;

    cout<<"type the no of ele"<<endl; 
    cin>>n;   

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }

    cout<<"enter the element to search"<<endl;
    cin>>key;

    int i;

    i=search(arr,key, n);

    cout<<i+1<<endl;

}