#include <iostream>
#include <string>
using namespace std;

// Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

// Example 1:

// Input:
// S = "0100110101"
// Output: 4
// Explanation: 
// The required substrings are 01, 0011, 01 and 01.

// Example 2:

// Input:
// S = "0111100010"
// Output: 3
 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function maxSubStr() which takes a string S and returns an integer as output.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= S.length <= 105


class Solution {
public:
    int maxSubStr(string str)
    {
        int sum=0; // to keep count of how many ones or zeors encountred
        int count=0; // keeps count of ans 
        int end=-1;  
        int n=str.size() ;
      
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='1')
                sum++;    // if 1 is found incremenrt sum
            else
                sum--;   // if zero is found decrement the sum
            
            if(sum==0)   // if it a valit que sum is always be zero when split is done
            {
                count++ ;  // increas as split occurs
                end=i;   // tellls whole is processed or not
            }
            
        }
        
        if(end!=n-1) // if arr is not pointing to last ele it is not a valid queestion
            return -1 ;
        
        return count;  //returning the ans
    }


};

int main() {
    Solution sol;
    string str;
    cout << "Enter a binary string: ";
    cin >> str;
    cout << "The maximum number of substrings with equal number of 0s and 1s is: " << sol.maxSubStr(str) << endl;
    return 0;
}
