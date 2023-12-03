#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// Given an array Arr[] that contains N integers (may be positive, negative or zero). 
//Find the product of the maximum product subarray.

// Example 1:

// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// Explanation: Subarray with maximum product
// is [6, -3, -10] which gives product as 180.
// Example 2:

// Input:
// N = 6
// Arr[] = {2, 3, 4, 5, -1, 0}
// Output: 120
// Explanation: Subarray with maximum product
// is [2, 3, 4, 5] which gives product as 120.

class Solution{
public:


    //algo is choose a -ve interger if exist such that it genartes prefix array and suffix array
    //wew calculate the prefix product max & suffix product max; if 0 is present in array of prefix 
    //and suffix array
    //we make the prefix and suffix to 1 and continue with the problem
    //at least get the mex of pre & suff retunr it

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
        
        long long prefix = 1 , suffix = 1 ;  //stroes the max of prefix array && sufix subarray
        long long maxi = INT_MIN ;   //stores max product
        
        for(int i = 0 ; i < n ; i++){
            if(prefix == 0 ) //if encounter 0 product becomes 0
                prefix = 1 ;
                
            if(suffix == 0 )
                suffix = 1 ;
            
            prefix = prefix * arr[i] ;  ///calculating prefix
            suffix = suffix * arr[n-1-i] ;///calculatng  ssuff product //iamgune the picture
            
            maxi = max(maxi , max(prefix , suffix));
        }
        
        return maxi ;
    }
};

int main() {
    // Create an object of Solution class
    Solution sol;
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // Input the elements of the array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Call the maxProduct method and store the result in a long long variable
    long long result = sol.maxProduct(arr, n);
    // Print the result
    cout << "The maximum product subarray is: " << result << endl;
    return 0;
}
