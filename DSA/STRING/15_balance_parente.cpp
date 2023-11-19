#include <iostream>
#include <stack>
using namespace std;

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

// Example 1:

// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balanced pairs, with 0 number of 
// unbalanced bracket.
// Example 2:

// Input: 
// ()
// Output: 
// true
// Explanation: 
// (). Same bracket can form balanced pairs, 
// and here only 1 type of bracket is 
// present and in balanced way.
// Example 3:

// Input: 
// ([]
// Output: 
// false
// Explanation: 
// ([]. Here square bracket is balanced but 
// the small bracket is not balanced and 
// Hence , the output will be unbalanced.
// Your Task:
// This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        
        if(x.length() == 1) 
            return false;
            
        for(int i = 0 ; i<x.length() ; i++){
        
            char ch = x[i];
            if(ch == '{' ||ch == '(' || ch == '[' ) 
                s.push(ch); 
               
            else if((ch == '}' && s.empty()) || (ch == ')' && s.empty())  || (ch == ']' && s.empty())) 
                return false;
                 
            else if((ch == '}' && s.top() == '{') || (ch == ')' && s.top() == '(')  || (ch == ']' && s.top() == '[' )) 
                s.pop();
            
            else if((ch == '}' && s.top() != '{') || (ch == ')' && s.top() != '(')  || (ch == ']' && s.top() != '[' )) 
                s.push(ch);
        }
        
        if(s.empty()) 
            return true;
        
        else 
            return false;
    }

};


int main() {
    Solution s;
    string x = "{()}[]";
    if (s.ispar(x)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }
    return 0; 
}

