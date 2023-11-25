#include <iostream>
#include <string>
using namespace std;

// Given a string S, find the longest palindromic substring in S. 
//Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
//Palindrome string: A string that reads the same backward. More formally, S is a palindrome if 
//reverse(S) = S. In case of conflict, return the substring which occurs first 
//( with the least starting index).

// Example 1:

// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".
// Example 2:

// Input: 
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the 
// longest palindromes with same length.
// The result is the one with the least
// starting index.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

// Expected Time Complexity: O(|S|2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 103


class Solution {
  public:
    string longestPalin (string S) {
        
        string ans="";
        int n=S.size();
        
        int maxl=0; //stores max length
        int l=0;  //stores the start index of ans
        int r=0; //end index of ans
        
        for(int i=0; i<n; i++){
            //if longest substring palindrome is of  odd lemgth
            int left=i;
            int right=i;
            
            while(left>=0 && right<=(n-1) && S[left]==S[right]){  //for odd is left and right are equal 
                                                                // we do left -- asnd right++
                  left--;       // note as it breaks the loop is pointing to left char of palindrom
                  right++;   ///same here
            }

            if(right-left+1>maxl){   // 
                maxl=right-left+1; 
                l=left+1;    // as it was pointing to mismatch char we are making l to point thr start of plaindrome
                r=right-1;   // as it was pointing to mismatch char we are making l to point thr end of plaindrome
            }
            
            //if longest substring palindrome is of  even lemgth
            left=i;
            right=i+1; //only diff for even

            while(left>=0 && right<=n-1 && S[left]==S[right]){
                left--;
                right++;            }
            if(right-left+1>maxl){
                maxl=right-left+1;
                l=left+1;
                r=right-1;
            }
        }
        
        for(int i=l; i<=r; i++){
            ans=ans+S[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string S;
    cout << "Enter a string: ";
    cin >> S;
    cout << "The longest palindrome substring is: " << sol.longestPalin(S) << endl;
    return 0;
}
