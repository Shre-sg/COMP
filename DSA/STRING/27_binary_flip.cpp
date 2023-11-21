#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
