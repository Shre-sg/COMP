#include <iostream>
#include <algorithm>
using namespace std;

// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.
// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in 
// the array sums up to 10.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.


// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)



// Declare an object of the class Solution
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
     bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);  //sorting to maker our work easier
        
        for(int i=0;i<n;i++){  
           int l = i+1;    // points o left most ele
           int r = n-1;   //points to right most ele
           
            while(l < r){      //do while l<r 
               int sum = A[i]+A[l]+A[r]; //calculaint sum
               
               if(sum == X) 
                    return true;  //if found
               
               else if(sum > X)   //is sum is greater ie it is sorted arr ie decremen r; 
                    r--;
               
               else 
                    l++;   //is sum issmaller ie it is sorted arr ie increment l; 
            }
        }
       return false;
    }

};



int main() {

    Solution obj;
    // Declare and initialize an array of integers, its size and a target sum
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int X = 22;

    // Call the function find3Numbers with the object, the array, its size and the target sum as arguments
    // Store the return value in a boolean variable
    bool ans = obj.find3Numbers(A, n, X);

    // Print the boolean variable to the standard output
    // Use std::boolalpha to print true or false instead of 1 or 0
    cout << boolalpha << ans << endl;

    // Return 0 from the main function
    return 0;
}
