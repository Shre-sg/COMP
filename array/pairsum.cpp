#include<iostream>
using namespace std;

bool pairsum(int arr[], int n, int k ){
    for(int i =0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==k)
            {
                cout<<i<<" "<< j<<endl;
                return true;
            }   
        }
    }
    return false;
}

int main(){
    int arr[]={2,4,7,11,14,16,20,21};
    int k=31;
    cout<<pairsum(arr,8,k)<<endl;

}


// optamising 

// two poniter method--> 
// low -->2 4 7 11 14 16 20 21<--high
//if i+j ==k print i, j then return true
// if i+j num is << than k , i++
// if i=j num is >> than k, j--
// do till low<high
//end return false
//git
