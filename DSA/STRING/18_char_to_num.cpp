// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
 
// Function which computes the sequence


//This part of the current page talks about how to convert a sentence into its equivalent
// mobile numeric keypad sequence. The line int position = input[i] - 'A'; 
//is part of the code that implements this algorithm. It explains how to find the 
//position of a character in the array that stores the keypad sequences. For example, 
//if the character is ‘A’, then the position is 0. If the character is ‘Z’, then the position is 25. 
//The position is calculated by subtracting the ASCII value of ‘A’ (which is 65) from 
//the ASCII value of the character. For example, the ASCII value of ‘Z’ is 90, 
//so the position is 90 - 65 = 25. This way, the position can be used to access the 
//corresponding keypad sequence from the array.

string printSequence(string arr[], string input)
{
    string output = "";
 
    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++) {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";
 
        else {
            // Calculating index for each
            // character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }
 
    // Output sequence
    return output;
}
 
// Driver Code
int main()
{
    // storing the sequence in array
    string str[]
        = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };
 
    string input = "GEEKSFORGEEKS";
    cout << printSequence(str, input);
    return 0;
}