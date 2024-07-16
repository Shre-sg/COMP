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

    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(int i=0 ; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}