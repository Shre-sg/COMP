#include <iostream>
#include <vector>
using namespace std;

// Product array puzzle
// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is 
//equal to the product of all the elements of nums except nums[i].

// Example 1:
// Input:
// n = 5
// nums[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900
// Explanation: 
// For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.

// Example 2:
// Input:
// n = 2
// nums[] = {12,0}
// Output:
// 0 12

// Your Task:
// You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
// Note: Try to solve this problem without using the division operation.
 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

//ALGO OPTAMISED TIME oder N && SPACE is also N
// ALGO : is to calulate the prefix product first without including the ith current el 
//         then again calculate suffix product wihtout including the ith current el
//         then multiply broth prefix n suff prodcut to get ans 
class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
        
        long long int suff[n], pre[n];    //store the product of pre & suff product
        vector<long long int> ans(n, 0);   //stores the final ans of vector

        pre[0] = 1;  //left most ele has no prefix ie 1
        pre[1] = a[0];  //1st index ele product will be a[0]* prefix[0] ie a[0]*1 
        for (int i = 2; i < n; i++) {  //calculating all prefix product same way 
            pre[i] = a[i - 1] * pre[i - 1];
        }

        suff[n - 1] = 1;   //right most ele has no suffix ie set to 1
        suff[n - 2] = a[n - 1]; //(n-1) th index ele product will be a[n-1]* prefix[n-1] ie a[n-1]*1 
        for (int i = n - 3; i >= 0; --i) {     //calculating all suffix product same way 
            suff[i] = a[i + 1] * suff[i + 1];
        }

        for (int i = 0; i < n; i++) {    //calculting the product ans 
            ans[i] = suff[i] * pre[i];
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<long long int> input = {1, 2, 3, 4};
    int n = input.size();

    vector<long long int> result = solution.productExceptSelf(input, n);

    cout << "Product vector except self at each index: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// https://youtu.be/gREVHiZjXeQ?si=HiqKTBndkCIxz7y2
//super optamised with time = N & space 1 
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> output;
//         if(n<1)
//             return output;
        
//         int product = 1;
//         for(int i=0;i<n;++i)
//         {
//             product *= nums[i];      //calculating all the prefix product
//             output.push_back(product);            
//         }
        
//         //Traverse from right and update output array
//         product = 1;
//         for(int i=n-1;i>0;--i)
//         {
//             output[i] = output[i-1]*product;   //this is algo editing & calcluting suffix 
//             product *= nums[i];                  //the one taken array 
//         }
//         output[0] = product;
        
//         return output;
//     }
// };