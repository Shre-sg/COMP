#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

// Example 1:

// Input:
// S = "001"
// Output: 1
// Explanation: 
// We can flip the 0th bit to 1 to have
// 101.


// Example 2:

// Input:
// S = "0001010111" 
// Output: 2
// Explanation: We can flip the 1st and 8th bit 
// bit to have "0101010101"
// 101.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minFlips() which takes the string S as input and returns the minimum number of flips required.


// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).



// Paste the solution class here
int minFlips (string s)
{
    // your code here
    int c1=0,c2=0;
    int i=0;
    //checking for 0101010101 combination  this string is taken as example for comparing wiht the
    //given input string
    while(i<s.length()){
        
        if(i%2==0 && s[i]!='0'){   //even place is not zero increment count1  
           c1++;
        }
        
        else if(i%2!=0 && s[i]!='1'){   //odd place not 1 increment count1 
           c1++;
        }
       
        i++;
    }
    
    i=0;
    //checking for 1010101010 combination, this string istaken as example o compare with the given string
    while(i<s.length()){
        
        if(i%2==0 && s[i]!='1'){      ///even place is not 1 increment count2 
          c2++;
        }
        
        else if(i%2!=0 && s[i]!='0'){  //odd place is not 0 increment count2 
          c2++;
        }
        
        i++;
    }
    //returning the minimum of it
    return min(c1,c2);
}

int main() {
  
  // Create a binary string to test
  string S = "0001010111";
  
  // Call the minFlips function and store the result
  int result = minFlips(S);
  
  // Print the result
  cout << "The minimum number of flips required is: " << result << endl;
  
  return 0;
}
