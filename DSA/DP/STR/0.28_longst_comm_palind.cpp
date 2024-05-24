// Longest Palindromic Subsequence | (DP-28)
// Problem Statement: Longest Palindromic Subsequence
// A palindromic string is a string that is equal to its reverse. For example: “Nitin” is a palindromic string. Now the question states to find the length of the longest palindromic subsequence of a string. It is that palindromic subsequence of the given string with the greatest length. We need to print the length of the longest palindromic subsequence.
// Pre-req: Longest Common Subsequence

// 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// memorization app
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

    int longestPalindromeSubseq(string s)
    {
        string t = s;
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        reverse(s.begin(), s.end());
        // sending the og str and revs str
        return f(t, s, n - 1, m - 1, dp);
    }
};

int main()
{
    Solution sol;
    string s = "bbbab";
    cout << "Length of the longest palindrome subsequence: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
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

    // Fill in the DP array
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

    // The value at dp[n][m] contains the length of the LCS
    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s)
{
    // Create a reversed copy of the string
    string t = s;
    reverse(s.begin(), s.end());

    // Call the LCS function to find the length of the Longest Common Subsequence
    return lcs(s, t);
}

int main()
{
    string s = "bbabcbcab";

    // Call the longestPalindromeSubsequence function and print the result
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence(s);
    return 0;
}
