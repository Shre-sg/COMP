#include<iostream>
using namespace std;


// Find the smallest positive missing number in the given array.
// Example: [0, -10, 1, 3, -20], Ans = 2

// Steps to Solve:
// 1. Build the Check[ ] array initialized with False at all indices.
// 2. By iterating over the array and marking non-negative a[i] as true i.e.
// if(a[i] >= 0)
// check[a[i]] = True
// 3. Iterate in the Check[ ] from i=1, BREAK the loop when you find check[i] =
// False and store that i in the ans variable.
// 4. Output the ans

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
