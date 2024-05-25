
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 44. Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.
// Seen this question in a real interview before?

class Solution
{
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
        {
            return false;
        }
        if (i < 0 && j >= 0)
        {
            for (int ii = j; ii >= 0; ii--)
                if (p[ii] != '*')
                    return false;
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*')
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};

int main()
{
    Solution solution;
    string s = "adceb";
    string p = "*a*b";
    cout << "Output: " << (solution.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}

// tabulation

#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i)
{
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++)
    {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    // Initialize the first row and column
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = isAllStars(S1, i);
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                if (S1[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    // The value at dp[n][m] contains whether S1 matches S2
    return dp[n][m];
}

int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}
