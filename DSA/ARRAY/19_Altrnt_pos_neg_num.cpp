#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with a positive number and 0 (zero) should be considered a positive element.
 

// Example 1:

// Input: 
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2
// Explanation : Positive elements : 9,4,5,0,2
// Negative elements : -2,-1,-5,-3
// As we need to maintain the relative order of
// postive elements and negative elements we will pick
// each element from the positive and negative and will
// store them. If any of the positive and negative numbers
// are completed. we will continue with the remaining signed
// elements.The output is 9,-2,4,-1,5,-5,0,-3,2.


class Solution{
public:

void rearrange(int arr[], int n) {
        // code here
        vector<int> positive;  //vectors that store +ve intergers
        vector<int> negative;  //vectors that store -ve interger
        
        for(int i = 0; i<n; i++){
            if(arr[i] < 0){
                negative.push_back(arr[i]); //adding all the -ve numbers
            }else{
                positive.push_back(arr[i]); //adding all +ve numbers
            }
        }
        
        vector<int> ans;  // noew vedctor to store ans
        
        int positive_size = positive.size();
        int negative_size = negative.size();
        
        int m = min(positive_size, negative_size); //trying find minarray
        
        for(int i = 0; i<m; i++){   //copy ele to array till one of the arry ends
            ans.push_back(positive[i]);  //addiing +ve
            ans.push_back(negative[i]);  //adding -ve IMP to use vectors
        }
        
        for(int i = m; i<positive_size; i++){  //does cuurr if min index is +ve ndex else ele is added
            ans.push_back(positive[i]);
        }
        
        for(int i = m; i<negative_size; i++){  //does cuurr if min index is -ve ndex else ele is added
            ans.push_back(negative[i]);
        }
        for(int i = 0; i<ans.size(); i++){   //cpoying all ele to intial vector
            arr[i] = ans[i];
        }
    }
};

#include <iostream>
#include <vector>
using namespace std;

int main(){
    Solution s; // create an object of the Solution class
    
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9}; // test array
    int n = sizeof(arr)/sizeof(arr[0]); // size of test array
    
    s.rearrange(arr,n); // call the rearrange method and modify the array
    
    for(int x : arr){ // loop through the array and print the elements
        cout << x << " ";
    }
    
    cout << endl;
    return 0;
}


