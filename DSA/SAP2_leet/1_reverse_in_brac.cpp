#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// 1190. Reverse Substrings Between Each Pair of Parentheses

// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        queue<char> q;
        string ans;
        for (char i : s)
        {
            if (i != ')')
                st.push(i);
            else
            {
                while (st.top() != '(')
                {
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while (!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "(u(love)i)";
    string result = solution.reverseParentheses(s);
    cout << "Result: " << result << endl; // Expected output: "iloveu"

    s = "(ed(et(oc))el)";
    result = solution.reverseParentheses(s);
    cout << "Result: " << result << endl; // Expected output: "leetcode"

    s = "a(bcdefghijkl(mno)p)q";
    result = solution.reverseParentheses(s);
    cout << "Result: " << result << endl; // Expected output: "apmnolkjihgfedcbq"

    return 0;
}
