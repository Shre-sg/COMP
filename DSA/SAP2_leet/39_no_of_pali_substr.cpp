#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 647. Palindromic Substrings

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution
{
public:
    bool solve(string &s, int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
        {
            return true;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        if (s[start] == s[end])
        {
            return dp[start][end] = solve(s, start + 1, end - 1, dp);
        }
        return dp[start][end] = false;
    }

    int countSubstrings(string s)
    {
        vector<vector<int>> dp(1002, vector<int>(1002, -1));
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (solve(s, i, j, dp))
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "abc";
    cout << "Test case 1: " << solution.countSubstrings(s1) << endl; // Output: 3

    // Test case 2
    string s2 = "aaa";
    cout << "Test case 2: " << solution.countSubstrings(s2) << endl; // Output: 6

    // Test case 3
    string s3 = "racecar";
    cout << "Test case 3: " << solution.countSubstrings(s3) << endl; // Output: 10

    // Test case 4
    string s4 = "abacdfgdcaba";
    cout << "Test case 4: " << solution.countSubstrings(s4) << endl; // Output: 13

    return 0;
}
