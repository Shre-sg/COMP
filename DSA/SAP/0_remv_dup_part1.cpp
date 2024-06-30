#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 1047. Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:

// Input: s = "azxxzy"
// Output: "ay"

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }

        string res;
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            res += c;
        }
        // important res=res+char == res+=char needs reversing
        // res=char+res needs no reversing
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "abbaca";
    string result = solution.removeDuplicates(s);
    cout << "Result: " << result << endl;
    return 0;
}
