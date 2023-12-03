#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an integer N, find its factorial. return a list of integers denoting the digits that 
//make up the factorial of N.

// Example 1:
// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120

// Example 2:
// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

class Solution {
public:
    vector<int> factorial(int N){

       vector<int> ans;

       ans.push_back(1);
       for(int i =2;i<=N;i++){
           
           int carry = 0;
           for(int j =0;j<ans.size();j++)
           {
               int data = ans[j] * i + carry;
               ans[j] = data%10;
               carry = data /10;
           }
           
           while(carry)
           {
               ans.push_back(carry%10);
               carry = carry/10;
           }
       
        }
        reverse(ans.begin(),ans.end());
       return ans;
    }
};

int main() {
    // Create an object of Solution class
    Solution sol;
    // Input a number
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // Call the factorial method and store the result in a vector
    vector<int> result = sol.factorial(n);
    // Print the result
    cout << "The factorial of " << n << " is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}
