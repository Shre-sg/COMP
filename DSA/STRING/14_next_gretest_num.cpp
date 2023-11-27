#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//thi  is basically the next permutaion code


// Implement the next permutation, which rearranges the list of 
//numbers into Lexicographically next greater permutation of list of numbers. 
//If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. 
//sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

// Example 1:

// Input: N = 6
// arr = {1, 2, 3, 6, 5, 4}
// Output: {1, 2, 4, 3, 5, 6}
// Explaination: The next permutation of the 
// given array is {1, 2, 4, 3, 5, 6}.
// Example 2:

// Input: N = 3
// arr = {3, 2, 1}
// Output: {1, 2, 3}
// Explaination: As arr[] is the last 
// permutation. So, the next permutation 
// is the lowest one.

//SHORTCUT 
//  next_permutation(arr.begin(), arr.end());
//         return arr;

//https://youtu.be/JDOXKqF60RQ?si=e05BUffGVpBqzNV-


class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int k = -1;
        //find k
        //start with second largest because chack decending
        for(int i =N-2;i>=0;i--)
        {
            if(arr[i] < arr[i+1])
            {
                k = i;
                break;
            }
        }
        
        // agr k nhi mila to sidha reverse
        if(k == -1)
        {
            reverse(arr.begin(),arr.end());
                return arr;
        }
        
        for(int i =N-1;i>=0;i--){
            if(arr[i] >arr[k])
            {
                swap(arr[i],arr[k]);
                    break; // ab agla 
            }
        }
        
        reverse(arr.begin()+k+1,arr.end());
        
        return arr;
        
    }
};

vector<int> nextPermutation(int N, vector<int> arr);

int main() {
    vector<int> arr = {1, 2, 3};
    int N = arr.size();
    vector<int> res = nextPermutation(N, arr);
    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


