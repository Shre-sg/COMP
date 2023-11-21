#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Paste the solution class here
// Sure, I can give you an example. Suppose the array of strings is:

// strs = [“flower”,“flow”,“flight”]1

// The initial value of prefix is the first string in the array, 
//which is “flower”. Then, the while loop starts and compares prefix with the 
//second string in the array, which is “flow”. Since prefix is longer than “flow” and 
//does not match it completely, the line of code:

// prefix = prefix.substr(0, prefix.length() - 1);23
// is executed and prefix becomes “flowe”. The comparison continues and the same line of code is 
//executed again, making prefix “flow”. Now, prefix matches the second string in the array completely,
// so the loop moves on to the third string in the array, which is “flight”. 
//Since prefix does not match the beginning of “flight”, the line of code:

// prefix = prefix.substr(0, prefix.length() - 1);23
// is executed and prefix becomes “flo”. The comparison continues and the same line of code 
//is executed again, making prefix “fl”. Now, prefix matches the beginning of “flight”, 
//so the loop ends. The final value of prefix is “fl”, which is the longest common prefix of 
//the array of strings


//STRING VECTOR LOOKS LIKE
    //vector<strimg> strs
    // strs ....>{shreays, james, romo,.....}
    //              0        1      2  ... n-1

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())  // sting vector is empty 
            return "";

        string prefix =strs[0];  //stores the ans

        for(auto s : strs){  //iterator goes from 0 to n-1 in vector 
            while(s.find(prefix)!= 0){   /// if prefix str in not found in the interator string s
                prefix = prefix.substr(0, prefix.length()-1);  //we reduce the prefix till match is foound
            }
        }
        return prefix;  //return prefix
    }
};



int main() {
  // Create a solution object
  Solution sol;
  
  // Create a vector of strings to test
  vector<string> strs = {"flower","flow","flight"};
  
  // Call the longestCommonPrefix function and store the result
  string result = sol.longestCommonPrefix(strs);
  
  // Print the result
  cout << "The longest common prefix is: " << result << endl;
  
  return 0;
}
