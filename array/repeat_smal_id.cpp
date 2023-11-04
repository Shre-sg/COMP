#include<iostream>

using namespace std;

int main(){
    int arr[100];

    int n;

    cout<<"type the no of ele"<<endl; 
    cin>>n;    

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];                ///takes input arry of 8  ele from index 0 to 7 
    }

    int index_arr[500];
    for(int i=0 ; i<n; i++){
        index_arr[i]=-1;                ///takes input arry of 8  ele from index 0 to 7 
    }

    int minindex=9999;
    for(int i=0; i<n; i++){
        
        if(index_arr[arr[i]]==-1){
            index_arr[arr[i]]=i;         ///am storing the index of ele read in arr into new array having the index value of ele read
        }
        else{
            minindex=min(minindex,index_arr[arr[i]]);  // i am checking if index arr has the index of ele read and if it 
                                                        //is smaller than any index prev index_min had??
        }
    }

    cout<<minindex+1<<endl;
}