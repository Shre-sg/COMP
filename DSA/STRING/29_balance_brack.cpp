#include <iostream>
#include <string>
using namespace std;


// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets.
// A string is considered balanced if it can be represented in the form S2[S1] where S1 and
// S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters.
// Calculate the minimum number of swaps necessary to make a string balanced.

// Note - Strings S1 and S2 can be empty.

// Example 1:

// Input  : []][][
// Output : 2
// Explanation :
// First swap: Position 3 and 4
// [][]][
// Second swap: Position 5 and 6
// [][][]

// Example 2:

// Input : [[][]]
// Output : 0 
// Explanation:
// String is already balanced.
 

// Your class definition here
//ALGO :  is bacially hoow many extra closing bracket count is there that will be the ans
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        
        int extra=0;  //keeps count of extra closing brack
        int ans=0;    // has ans after simplification  
        
        for(auto i:S)
        {
            if(i=='[')
            {
                if(extra>0) //storing the max extra closing breacket count 
                    ans+=extra;   //in ans
                
                extra--;   // as open bt
            }
            else if(i==']') //if encounted first
            {
                extra++;  // this is where extra closing bracket is incremented
            }
        }
        return ans;
    }
};

int main()
{
    // Create an object of Solution class
    Solution sol;

    // Test some sample inputs
    string S1 = "[]][][";
    string S2 = "[[][]]";
    string S3 = "]]][[[";
    
    // Print the outputs
    cout << "Minimum number of swaps for " << S1 << " is " << sol.minimumNumberOfSwaps(S1) << endl;
    cout << "Minimum number of swaps for " << S2 << " is " << sol.minimumNumberOfSwaps(S2) << endl;
    cout << "Minimum number of swaps for " << S3 << " is " << sol.minimumNumberOfSwaps(S3) << endl;

    return 0;
}
