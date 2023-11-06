#include<iostream>
using namespace std;

//Given an unsorted array A of size N of non-negative integers, find a continuous
// subarray which adds to a given number S

int main(){
    int arr[100];

    int n, key;

    cout<<"type the no of ele"<<endl; 
    cin>>n;    

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];                ///takes input arry of 8  ele from index 0 to 7 
    }

    cin>> key;

//brute force
//     for (int i = 0; i < n; i++)
//   {
//     int sum = 0;
//     for (int j = i; j < n; j++)
//     {
//       // Calculate required sum
//       sum += arr[j];
//       // Check if sum is equal to required sum
//       if (sum == k)
//         cout<< i+1; << j<<endl;
//     }
//   }
//   cout << (res) << endl;

    //optamised;

    int i=0, j=0, st=-1, en=-1, sum=0;

    while(j<n && sum+arr[j]<=key){  //breaks when the sum> key where " j index is noted" & j reaches the  n end of array
        sum=sum+arr[j];
        j++;
    }
    if(sum==key){
        cout<< i+1 <<" "<< j<<endl;
        return 0;
    }
    while(j<n){  //hapens when sum!= key (sum>key or j ranout as sum < key)
        sum=sum +arr[j] ; //need when sum > key but j didt ran out
       
        while(sum>key){    //sum gets equall && can be less than key depends are arr[i]
             sum=sum-arr[i];
             i++;
        }
       
        if(sum==key ){   
            st=i+1;
            en=j+1;
            break;
        }       
        j++;

    }

    cout<< st <<" "<< en <<endl;

}
