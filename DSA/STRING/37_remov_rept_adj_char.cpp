#include <iostream> // include the header file for input/output streams
#include <string> // include the header file for string class
using namespace std; // use the standard namespace


// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

// Example 1:

// Input:
// S = aabb
// Output:  ab 
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.

// Example 2:

// Input:
// S = aabaa
// Output:  aba
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// 'a' at fifth position is appearing
// 2nd time consecutively.
 

// Your Task:
// You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.
 

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).
 


class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string str="";
        for(int i=1;i<S.length();i++){
            if(S[i]==S[i-1]){
                S[i-1]='0';
            }
        
        }
        for(int i=0;i<S.length();i++){
            if(S[i]!='0'){
                str+=S[i];
            }
        }
        return str;
    }
};

int main () // declare the main function
{
    Solution obj; // create an object of the Solution class
    string s = "aabbbccdde"; // create a string variable
    cout << obj.removeConsecutiveCharacter(s); // print the return value of the method
    return 0; // return 0 to indicate success
}
