
#include <iostream>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

// Given two strings s and goal, return true if and only if s 
//can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 



class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) 
            return false;
    
        string ans=s+s;    //// abcdabcd check is adab is substring of abcdabcd  
                             //-->abcd     ---->cdab     
        if(ans.find(goal)!=string::npos){
            return true;
        }   
        else{ 
            return false;
        }
    }
};


int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";
    bool result = sol.rotateString(s, goal);
    cout << "Result: " << result << endl;
    return 0;
}

