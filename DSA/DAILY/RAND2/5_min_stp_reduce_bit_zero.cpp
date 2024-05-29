// https://youtu.be/pFPHVAKFhNo

// 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.

// Example 1:

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14.
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.
// Step 5) 4 is even, divide by 2 and obtain 2.
// Step 6) 2 is even, divide by 2 and obtain 1.
// Example 2:

// Input: s = "10"
// Output: 1
// Explanation: "10" corressponds to number 2 in their decimal representation.
// Step 1) 2 is even, divide by 2 and obtain 1.
// Example 3:

// Input: s = "1"
// Output: 0

// Constraints:

// 1 <= s.length <= 500
// s consists of characters '0' or '1'
// s[0] == '1'

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int carry = 0, steps = 0;

        // Iterate from the end of the string to the start
        for (int i = s.length() - 1; i > 0; i--)
        {
            // If the current bit is '1' and there's no carry, or the bit is '0' and there's a carry,
            // this means we need to add 1 (making the number odd if it was even or even if it was odd),
            // then divide by 2
            if ((s[i] - '0') + carry == 1)
            {
                steps += 2; // One step to add 1, another step to divide by 2
                carry = 1;  // After addition, the carry will always be 1
            }
            else
            {
                // If the current bit is '0' and there's no carry, or the bit is '1' and there's a carry,
                // just divide by 2
                steps++;
            }
        }
        return steps + carry; // Add carry to the steps for the final adjustment if needed
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "1101";
    string test2 = "10";
    string test3 = "1";
    string test4 = "1111011110000011100000110001011011110010111001010111110001";

    cout << "Number of steps for " << test1 << ": " << solution.numSteps(test1) << endl;
    cout << "Number of steps for " << test2 << ": " << solution.numSteps(test2) << endl;
    cout << "Number of steps for " << test3 << ": " << solution.numSteps(test3) << endl;
    cout << "Number of steps for " << test4 << ": " << solution.numSteps(test4) << endl;

    return 0;
}
