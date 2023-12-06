#include <iostream>
#include <algorithm>

using namespace std;


// Given an array Arr[] of size L and a number N, you need to write a program to find if 
//there exists a pair of elements in the array whose difference is N.

// Example 1:

// Input:
// L = 6, N = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output: 1
// Explanation: (2, 80) have difference of 78.
// Example 2:

// Input:
// L = 5, N = 45
// arr[] = {90, 70, 20, 80, 50}
// Output: -1
// Explanation: There is no pair with difference of 45.
// Your Task:
// You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

// Expected Time Complexity: O(L* Log(L)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=L<=104 
// 1<=Arr[i]<=105 

// 0<=N<=105



bool findPair(int arr[], int size, int n){
   sort(arr,arr+size);
   
   int i=0;  //important
   int j=1;
   
   while(i<size && j<size){
       
       int diff = arr[j]-arr[i];
       
       if(i!=j && diff==n){
           return true;
       }
       
       else if(diff<n){
           j++;
       }
       
       else{
           i++;
           
           if(i==j){
              j++;
           }
       }
   }
   
   return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 5;
    if(findPair(arr, size, n)){
        cout << "Pair found.";
    }else{
        cout << "Pair not found.";
    }
    return 0;
}


//unorderd map way of doing it
// public boolean findPair(int arr[], int size, int n)
//     {
//         HashSet<Integer> list = new HashSet<Integer>();
        
//         for(int a: arr)
//         {
//             list.add(a);
//         }
//         if(n==0 && list.size() == size)
//          return false;
//         for(int i=0;i<size;i++)
//         {
//             int  y = arr[i] + n;
//             if(list.contains(y))
//             return true;
//         }
//         return false;
//     }

