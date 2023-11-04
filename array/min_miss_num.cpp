#include<iostream>

using namespace std;

int main(){
    int arr[100];

    int n, key;

    cout<<"type the no of ele"<<endl; 
    cin>>n;    

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];               
    }

    bool check[999];
    for(int i=0 ; i<999; i++){
        check[i]=false;                
    }

    for(int i=0; i<n; i++){
        if(arr[i]>=0)
            check[arr[i]]=true;
    }

    for(int j=0; j<n; j++){
        if(check[j]==false){
            cout<<j<<endl;
            break;
        }
    }

}
