#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//https://youtu.be/Ydho2JPTI3Y?si=mkV4Mgo48GlmUKyT
// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// s = V
// Output: 5
// Example 2:

// Input:
// s = III 
// Output: 3


// note that ALL THE ROMAN HAS H9GHER TO LOWERS VALUE LETTR
//IF HIGHER IS SECOD AND LOWER VALUE CHAR IS FIRST WE HAVE MINU THE LOWER VALUE IN ANS
// The given code for the Solution class
class Solution {
  public:
    int romanToDecimal(string &s) {
       unordered_map<char,int> mymap{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
        };
        int value = 0;
        for(int i=0;i<s.size();++i){    //TRAVERSING
            if(mymap[s[i]] < mymap[s[i+1]])   //ALGO CHECK
                value -= mymap[s[i]];    
            else
                value += mymap[s[i]];
        }
        return value;
    }   
};

// The main function
int main() {
    // Create an object of the Solution class
    Solution sol;

    // Declare a string variable to store the roman numeral
    string s;

    // Prompt the user to enter a roman numeral
    cout << "Enter a roman numeral: ";

    // Read the input from the user
    cin >> s;

    // Call the romanToDecimal method of the Solution class and store the result
    int result = sol.romanToDecimal(s);

    // Print the result
    cout << "The decimal value of " << s << " is " << result << endl;

    // Return 0 to indicate successful termination
    return 0;
}
