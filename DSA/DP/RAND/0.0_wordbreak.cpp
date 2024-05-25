#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

// 139. Word Break

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

class Solution
{
public:
    bool check(string s, set<string> &st, map<string, bool> &mp)
    {
        int n = s.length();

        if (n == 0)
            return true;

        if (mp.find(s) != mp.end())
            return mp[s];

        for (int i = 0; i < s.length(); i++)
        {
            string pre = s.substr(0, i + 1); // current prefix string
            string suf = s.substr(i + 1);    // left over suffix string

            if (st.find(pre) != st.end() && check(suf, st, mp) == true)
                return mp[s] = true;
        }
        return mp[s] = false;
    }

    bool wordBreak(string s, vector<string> &dict)
    {
        set<string> st;
        for (int i = 0; i < dict.size(); i++)
            st.insert(dict[i]);

        map<string, bool> mp;
        return check(s, st, mp);
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};

    cout << "Output: " << (solution.wordBreak(s, dict) ? "true" : "false") << endl;

    s = "applepenapple";
    dict = {"apple", "pen"};
    cout << "Output: " << (solution.wordBreak(s, dict) ? "true" : "false") << endl;

    s = "catsandog";
    dict = {"cats", "dog", "sand", "and", "cat"};
    cout << "Output: " << (solution.wordBreak(s, dict) ? "true" : "false") << endl;

    return 0;
}
