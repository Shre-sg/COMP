#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

// Example 1:

// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.
// Example 2:

// Input:
// N = 7, M = 3
// A = {7, 3, 2, 4, 9, 12, 56}
// Output: 2
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following M packets :{3, 2, 4}.

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());  //sort the aray
    int i=0, j;

    long long min_=INT_MAX;
    while(i<=n-m){  
        j=i+m-1;  
        min_=min(a[j]-a[i],min_);
        i++;
    }
    return min_;
    
    }   
};


int main() {
    Solution obj;
    // Declare and initialize a vector of long long integers, its size and another long long integer m
    std::vector<long long> a {7, 3, 2, 4, 9, 12, 56};
    long long n = a.size();
    long long m = 3;

    // Call the function findMinDiff with the object, the vector, its size and m as arguments
    // Store the return value in a long long variable
    long long ans = obj.findMinDiff(a, n, m);

    // Print the long long variable to the standard output
    std::cout << ans << std::endl;

    // Return 0 from the main function
    return 0;
}
