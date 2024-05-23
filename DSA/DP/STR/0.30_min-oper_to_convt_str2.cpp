// Minimum Insertions/Deletions to Convert String | (DP- 30)

// Problem Statement: Minimum Insertions/Deletions to Convert String A to String B
// We are given two strings, str1 and str2. We are allowed the following operations:

// Delete any number of characters from string str1.
// Insert any number of characters in string str1.
// We need to tell the minimum operations required to convert str1 to str2.

//
/// code
// 583. Delete Operation for Two Strings

// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

// Example 1:
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

// Constraints:

// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 249K
// Submissions
// 404.3K

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
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
    int minDistance(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        // Calculate the length of the longest common subsequence between str1 and str2
        int k = lcs(str1, str2);

        // Calculate the minimum operations required to convert str1 to str2
        return (n - k) + (m - k);
    }

    // deletions = n- len(lcs)
    // insertion = m - len(lcs)
    // ie (n - k) + (m - k); or n+m - 2*len(lcs);
};

int main()
{
    Solution sol;
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int result = sol.minDistance(str1, str2);
    cout << "Minimum number of operations to convert str1 to str2: " << result << endl;

    return 0;
}