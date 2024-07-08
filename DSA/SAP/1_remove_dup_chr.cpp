#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 1209. Remove All Adjacent Duplicates in String II

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation:
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"

// Constraints:

// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        // <chat, int> <char present, its occurance>;

        for (int i = 0; i < s.size(); ++i)
        {
            if (!st.empty() && st.top().first == s[i])
            {
                st.top().second++;
                if (st.top().second == k)
                {
                    st.pop();
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }

        string res;
        while (!st.empty())
        {
            auto p = st.top();
            st.pop();
            res += string(p.second, p.first);
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
    string s = "deeedbbcccbdaa";
    int k = 3;
    string result = solution.removeDuplicates(s, k);
    cout << "Result: " << result << endl;
    return 0;
}