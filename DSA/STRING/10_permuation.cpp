#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA .
// Example 2:

// Input: ABSG
// Output:
// ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
// BASG BGAS BGSA BSAG BSGA GABS GASB 
// GBAS GBSA GSAB GSBA SABG SAGB SBAG 
// SBGA SGAB SGBA
// Explanation:
// Given string ABSG has 24 permutations.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function find_permutation() which takes the string S as input parameter and returns a vector of string in lexicographical order.

// Expected Time Complexity: O(n! * n)
// Expected Space Complexity: O(n! * n)

// Constraints:
// 1 <= length of string <= 5


vector<string>find_permutation(string s)
        {
         sort(s.begin(),s.end());    //enable to print in lexigraph order
         
         vector<string>ans;  // new vec to store answer
         
         ans.push_back(s);   // this is to print the first permutaion ie the given string itself
         
         while(next_permutation(s.begin(),s.end())){   //this is print all other permutaion from first
            ans.push_back(s);
         }
         
         return ans;
        }

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    vector<string> ans = find_permutation(s);
    cout << "The permutations of the string are: " << endl;
    for (string p : ans) {
        cout << p << endl;
    }
    return 0;
}
