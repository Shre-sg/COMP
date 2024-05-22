
#include <bits/stdc++.h>
using namespace std;

// Longest Common Substring | (DP - 27)
// Problem Statement: Longest Common Substring
// A substring of a string is a subsequence in which all the characters are consecutive. Given two strings, we need to find the longest common substring.
// We need to print the length of the longest common substring.

// Function to find the length of the Longest Common Substring (LCS)
int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP table with dimensions (n+1) x (m+1)
    vector<vector<int>> dp(n + 1, vector(m + 1, 0));

    int ans = 0; // Initialize the answer variable

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1]; // Characters match, increment substring length
                dp[i][j] = val;                 // Update the DP table
                ans = max(ans, val);            // Update the maximum substring length found so far
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
        }
    }

    return ans; // Return the length of the Longest Common Substring
}

int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
