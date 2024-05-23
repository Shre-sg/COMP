// 1312. Minimum Insertion Steps to Make a String Palindrome
// Solved
// Hard
// Topics
// Companies
// Hint
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

// memorization
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int f(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        // base case
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        // both characters match
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(s1, s2, ind1 - 1, ind2 - 1, dp);
        else // characters do not match
            return dp[ind1][ind2] = max(f(s1, s2, ind1, ind2 - 1, dp), f(s1, s2, ind1 - 1, ind2, dp));
    }
    int minInsertions(string s)
    {
        string t = s;
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        reverse(s.begin(), s.end());
        return s.size() - f(t, s, n - 1, m - 1, dp);
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = sol.minInsertions(s);
    cout << "Minimum insertions to make the string a palindrome: " << result << endl;
    return 0;
}

// tabulation
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

// Function to calculate the minimum insertions required to make a string palindrome
int minInsertion(string s)
{
    int n = s.size();
    int k = longestPalindromeSubsequence(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

int main()
{
    string s = "abcaa";

    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion(s);
    return 0;
}
