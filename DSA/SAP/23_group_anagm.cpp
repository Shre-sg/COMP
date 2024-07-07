#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // for sort

using namespace std;

// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Hash table to store sorted strings as keys and original strings as values
        unordered_map<string, vector<string>> mp;

        for (auto x : strs)
        {
            string word = x;
            // Sort the characters in the current word
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>> ans;

        // Extract the original strings grouped by their sorted versions
        for (auto x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution;
    vector<vector<string>> groups = solution.groupAnagrams(strs);

    cout << "Groups of anagrams:" << endl;
    for (const vector<string> &group : groups)
    {
        for (const string &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

// {
//   "aet": ["eat", "tea", "ate"],
//   "ant": ["tan", "nat"],
//   "abt": ["bat"]
// }