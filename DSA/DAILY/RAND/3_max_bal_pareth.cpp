#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Longest Valid Parentheses

// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
// substring
// .

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

// Explain with an example:
// s = "(()())"

// Initial stack: [-1], maxL: 0
// why we intialise with -1?
// ~ : Consider a case that s= "()" or any string with a valid paranthesis at the beginning, we want the gap between the previous invalid case, but if there is valid paranthesis at the beginning, there is no previous invalid case, to indicate that, we push -1 into the stack, here at index=1, max len = 1-(-1)=2

// i=0: s[0] = '(', push 0 onto stack: [-1, 0]

// i=1: s[1] = '(', push 1 onto stack: [-1, 0, 1]

// i=2: s[2] = ')', pop from stack (1 is the top element), update maxL to 2 - (-1) = 3: [-1, 0]

// i=3: s[3] = '(', push 3 onto stack: [-1, 0, 3]
// 6.i=4: s[4] = ')', pop from stack (3 is the top element), update maxL to 4 - 0 = 4: [-1]

// i=5: s[5] = ')', pop from stack (0 is the top element), update maxL to 5 - (-1) = 6: []

// Final maxL: 6 (length of the longest valid parentheses substring)

// Complexity
// Time complexity:
// O(N) As we have used stack and did push & pop operations simultaneoulsy.

// Space complexity:
// O(N)
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1); // Push -1 onto stack to handle edge case when the first character is ')'
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push(i); // Push index of '(' onto stack
            }
            else
            {
                st.pop(); // Pop corresponding '(' index
                if (st.empty())
                {
                    st.push(i); // If stack becomes empty, push current index to represent the start of a new substring
                }
                else
                {
                    int len = i - st.top();    // Calculate length of current valid substring
                    maxLen = max(len, maxLen); // Update max length if needed
                }
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    string input = "(()))())(";
    cout << "Length of the longest valid parentheses substring: " << solution.longestValidParentheses(input) << endl;
    return 0;
}
