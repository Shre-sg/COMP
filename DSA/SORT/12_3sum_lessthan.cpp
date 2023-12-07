#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Given an array arr[] of distinct integers of size N and a value sum, the task is 
//to find the count of triplets (i, j, k), having (i<j<k) with the sum of 
//(arr[i] + arr[j] + arr[k]) smaller than the given value sum.


// Example 1:


// Input: N = 4, sum = 2
// arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with 
// sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
 

// Example 2:


// Input: N = 5, sum = 12
// arr[] = {5, 1, 3, 4, 7}
// Output: 4
// Explanation: Below are triplets with 
// sum less than 12 (1, 3, 4), (1, 3, 5), 
// (1, 3, 7) and (1, 4, 5).

// Your Task:
// This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countTriplets() that take array arr[], integer N  and integer sum as parameters and returns the count of triplets.


// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(1).

//Your class Solution
//3 pointer approach
class Solution{
	public:
		long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long count=0;
	    for(int k=0;k<n-2;k++){
	        int i=k+1;
	        int j=n-1;
	        while(j>i){
	            long long x=arr[i]+arr[j]+arr[k];
	            if(x<sum){
	                count+=(j-i);
	                i++;
	            }
	            else{
	                j--;
	            }
	        }
	    }
	    return count;
	}
};

//Main function
int main()
{
    //Creating an object of class Solution
    Solution obj;
    
    //Taking input for the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    //Declaring an array of size n
    long long arr[n];
    
    //Taking input for the elements of the array
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    //Taking input for the sum value
    long long sum;
    cout << "Enter the sum value: ";
    cin >> sum;
    
    //Calling the countTriplets function and printing the result
    long long result = obj.countTriplets(arr, n, sum);
    cout << "The number of triplets with sum less than " << sum << " is: " << result << endl;
    
    return 0;
}
