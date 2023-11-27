#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Given a string S consisting of only opening and closing curly brackets '{' and '}',
// find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

// Example 1:

// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.
// Example 2:

// Input: 
// S = "{{}{{{}{{}}{{"
// Output: -1
// Explanation: There's no way we can balance
// this sequence of braces.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countRev() 
//which takes the string S as the input parameter and returns the minimum number of reversals 
//required to balance the bracket sequence. If balancing is not possible, return -1. 

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).



int countRev (string s)
{
    int ans=0;
    int n=s.size();
    
    if(n%2 != 0)    ///if it is not even its ubable to balance
        return -1;
    
    stack<char>st;  //stack
    
    for(int i=0;i<n;i++){
        if(s[i]=='{')       //push
            st.push(s[i]);
        
        else{               //if we encounter } 
            
            if(st.empty()) {    // start has } we just push
                ans++;          //counts the ans
                st.push('{');
            }
            
            else {
                st.pop();           //stack is not empty we just push it 
            }
        }
    }
    
    int N= st.size();   //at the end {{{{ will be left is we add N/2 to ans as it takes that much operation to correct
    ans+=N/2;
    
    return ans;
    
}

int main () {
  std::string input;
  std::cin >> input; // read input string
  int result = countRev (input); // call countRev function
  std::cout << result << std::endl; // print result
  return 0; // return 0
}
