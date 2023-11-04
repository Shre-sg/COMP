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

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++ ){
            if(arr[j]< arr[i]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(int i=0 ; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}