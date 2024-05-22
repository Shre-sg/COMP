#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 131. Palindrome Partitioning

// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// . Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 868.3K
// Submissions
// 1.3M
// Acceptance Rate
// 68.9%

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &result)
    {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length())
        {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end)
        {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1))
            {
                path.push_back(s.substr(start, end - start));
                // Recur to find other partitions
                backtrack(s, end, path, result);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    vector<vector<string>> partitions = sol.partition(s);

    cout << "Palindromic partitions of the string \"" << s << "\":" << endl;
    for (const auto &partition : partitions)
    {
        for (const auto &str : partition)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &result)
    {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length())
        {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end)
        {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1))
            {
                path.push_back(s.substr(start, end - start));
                // Recur to find other partitions
                backtrack(s, end, path, result);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    vector<vector<string>> partitions = sol.partition(s);

    cout << "Palindromic partitions of the string \"" << s << "\":" << endl;
    for (const auto &partition : partitions)
    {
        for (const auto &str : partition)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
