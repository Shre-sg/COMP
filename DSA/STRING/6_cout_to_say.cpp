#include <iostream>
#include <string>
using namespace std;


// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
//which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of 
//substrings such that each substring contains exactly one unique digit. 
//Then for each substring, say the number of digits, then say the digit. Finally, 
//concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":

// Given a positive integer n, return the nth term of the count-and-say sequence.

 

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 


class Solution {
public:
    string countAndSay(int n) {
        if(n==1)                            // base case
            return "1";
        
        string str = countAndSay(n-1);    //recursu=ively call the func
        int i=0;        
        string res ="";    // to store the asn
        while(i<str.size()){     // iteerae thru the str lem we got after recursion 
            char c = str[i];      // we storing the first ele in c 
            int count = 0;   // keeps tarck of the how many rtimes the char has repeated
            while(i<str.size() && str[i]==c){   // this couts the how many is repeated
                count++;    // increment as it is repeated
                i++;   // movw the index as it goes on counting 
            }   
            res=res+to_string(count);   // concatining the ans
            res=res+c;  // as then which num got reppeated get addded
        }
        return res;
            
    }
};

int main() {
    Solution s;
    int n = 5;
    cout << "The " << n << "th term of the count-and-say sequence is: " << s.countAndSay(n) << endl;
    return 0;
}
