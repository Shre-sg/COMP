#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty() ||
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << boolalpha; // Print bool values as true/false

    cout << "Test case 1: " << solution.isValid(test1) << endl; // Expected output: true
    cout << "Test case 2: " << solution.isValid(test2) << endl; // Expected output: true
    cout << "Test case 3: " << solution.isValid(test3) << endl; // Expected output: false
    cout << "Test case 4: " << solution.isValid(test4) << endl; // Expected output: false
    cout << "Test case 5: " << solution.isValid(test5) << endl; // Expected output: true

    return 0;
}
