#include<iostream>

using namespace std;

int main(){
     int arr[100];

    int key, n;

    cout<<"type the no of ele"<<endl; 
    cin>>n;   

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }

    //no.of subarr is n*(n+1)/2

    //sum of sub arr
    int sum=0; 
    for(int i= 0; i<n; i++){
            
        int sum=0;   ///as sub arry sum is cal sum gets reset 
        
        for(int j=i; j<n; j++){
            sum=sum+arr[j];
            cout<<sum<<endl;  // to print subarr repalce sum by arr[j]
        }
    }

}