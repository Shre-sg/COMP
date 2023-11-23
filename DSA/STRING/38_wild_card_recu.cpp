#include <iostream> // include the header file for input/output streams
#include <string> // include the header file for string class
using namespace std; // use the standard namespace


// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

// * --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
// ? --> This character in string wild can be replaced by any one character.
// Example 1:

// Input: wild = ge*ks
//        pattern = geeks
// Output: Yes
// Explanation: Replace the '*' in wild string 
// with 'e' to obtain pattern "geeks".
// Example 2:

// Input: wild = ge?ks*
//        pattern = geeksforgeeks
// Output: Yes
// Explanation: Replace '?' and '*' in wild string with
// 'e' and 'forgeeks' respectively to obtain pattern 
// "geeksforgeeks"

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

// Expected Time Complexity: O(length of wild string * length of pattern string)
// Expected Auxiliary Space: O(length of wild string * length of pattern string)

// Constraints:
// 1<=length of the two string<=10^3 


class Solution{
    public:
    bool fun(int i, int j, int m , int n, string wild,string pattern)
    {
        
        if(i==m && j==n)
            return true;
        
        if(j==n)
        {
            while(i<m)
            {
                if(wild[i]=='*')
                    i++;
                else
                    return false ;
            }
            return true ;
        }
        
        if(i==m || j==n)
            return false;
        
        if(wild[i] == pattern[j])
        {
            return fun(i+1,j+1,m,n,wild,pattern);
        }
        
        else if(wild[i]=='?')
        {
            return fun(i+1,j+1,m,n,wild,pattern);
        }
        
        else if(wild[i]=='*')
        {
            bool flag=false ;
            
            for(int index=j;index<=n;index++)
            {
                flag=flag || fun(i+1,index,m,n,wild,pattern);
            }
            return flag ;
        }
        
        else
            return false ;
    }
    
    bool match(string wild, string pattern)
    {
        int m=wild.size(),n=pattern.size();
            return fun(0,0,m,n,wild,pattern);
    }
};

int main () // declare the main function
{
    Solution obj; // create an object of the Solution class
    string wild = "*a?b*"; // create a string variable for the wildcard pattern
    string pattern = "abcde"; // create a string variable for the input string
    cout << boolalpha << obj.match(wild, pattern); // print the return value of the method in true/false format
    return 0; // return 0 to indicate success
}
