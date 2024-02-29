#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// First non-repeating character in a stream
// Given an input stream A of n characters consisting only of lower case alphabets. While
// reading characters from the stream, you have to tell which character has appeared only once
// in the stream upto that point. If there are many characters that have appeared only once,
// you have to tell which one of them was the first one to appear. If there is no such character
// then append '#' to the answer.

// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every i you need to consider the string from starting
// position till ith position.

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every ith character we will
// consider the string from index 0 till index i first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - there are two non repeating characters 'b' and 'c',
// first non-repeating character is 'b' because 'b' comes before
// 'c' in the stream.
// Example 2:

// Input: A = "zz"
// Output: "z#"
// Explanation: For every character first non
// repeating character is as follow-
// "z" - first non-repeating character is 'z'
// "zz" - no non-repeating character so '#'

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string ans;
        unordered_map<char, int> count;
        queue<char> q;

        for (int i = 0; i < A.length(); i++)
        {
            char var = A[i];

            q.push(var);
            count[var]++;

            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans = ans + q.front();
                    break;
                }
            }

            if (q.empty())
            {
                ans = ans + "#";
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string input = "aabbccddeeffgghh";
    string result = sol.FirstNonRepeating(input);
    cout << "First non-repeating character for input \"" << input << "\" is: " << result << endl;

    return 0;
}
