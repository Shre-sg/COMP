#include <iostream>
#include <string>

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

// 1.)BRUTE FORCE
// T.C.-->O(N^3)
// S.C.-->O(1)
class Solution
{
private:
    bool ispalind(int i, int j, std::string s)
    {
        if (i > j)
        {
            return true;
        }
        if (s[i] == s[j])
        {
            return ispalind(i + 1, j - 1, s);
        }
        else
        {
            return false;
        }
        return false;
    }

public:
    int countSubstrings(std::string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool what = ispalind(i, j, s);
                if (what == true)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    std::string s = "abc";
    int result = solution.countSubstrings(s);
    std::cout << "The number of palindromic substrings in \"" << s << "\" is: " << result << std::endl;

    s = "aaa";
    result = solution.countSubstrings(s);
    std::cout << "The number of palindromic substrings in \"" << s << "\" is: " << result << std::endl;

    return 0;
}

// 2.)MEMOIZATION
// T.C.-->O(N^2)
// S.C.-->O(1)

// class Solution
// {
// private:
//     bool ispalind(int i, int j, string s, vector<vector<int>> &dp)
//     {
//         if (i > j)
//         {
//             return true;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         if (s[i] == s[j])
//         {
//             return dp[i][j] = ispalind(i + 1, j - 1, s, dp);
//         }
//         else
//         {
//             return dp[i][j] = false;
//         }
//         return dp[i][j] = false;
//     }

// public:
//     int countSubstrings(string s)
//     {
//         int n = s.length();
//         int ans = 0;
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 bool what = ispalind(i, j, s, dp);
//                 if (what == true)
//                 {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 3.)SMART WAY
// T.C.->O(N^2)
// S.C.-->O(1)
// BUT FASTER THAN MEMOIZATION

// class Solution {
//     int count=0;
//     private:
//     int check(string s,int i,int j,int n)
//     {
//         while(i>=0&&j<n&&s[i]==s[j])
//         {
//             count++;
//             i--;
//             j++;
//         }
//         return 0;
//     }
// public:
//     int countSubstrings(string s) {
//         int n=s.length();
//         for(int i=0;i<n;i++)
//         {
//             check(s,i,i,n);
//             check(s,i,i+1,n);
//         }
//         return count;
//     }
// };