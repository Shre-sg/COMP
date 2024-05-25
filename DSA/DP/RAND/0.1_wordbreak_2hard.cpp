#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// 140. Word Break II

// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.
// Input is generated in a way that the length of the answer doesn't exceed 105.

class Solution
{
public:
    // Function to recursively form sentences from the string s
    void solve(const string &s, int ind, const unordered_set<string> &wordSet, string &curr, vector<string> &result)
    {
        // Base case when we reach the end of the string s
        if (ind == s.length())
        {
            result.push_back(curr);
            return;
        }

        // Loop from ind+1 to the end of the string to form possible words
        for (int end = ind + 1; end <= s.length(); ++end)
        {
            // Substring from ind to end
            string word = s.substr(ind, end - ind);

            // If the word is in the dictionary, continue to form sentences
            if (wordSet.find(word) != wordSet.end())
            {
                // Add word to current sentence
                string prev = curr.empty() ? word : (curr + " " + word);
                // Recursive call for the next part of the string
                solve(s, end, wordSet, prev, result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        // Store dictionary words in a set for quick lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // Vector to store all possible sentences
        vector<string> ans;
        // Current sentence being formed
        string curr;
        // Start the recursive function
        solve(s, 0, wordSet, curr, ans);
        return ans;
    }
};

int main()
{
    // Input string and dictionary
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    // Create an instance of the Solution class
    Solution solution;

    // Call the wordBreak function
    vector<string> results = solution.wordBreak(s, wordDict);

    // Output the results
    cout << "Possible sentences:" << endl;
    for (const string &sentence : results)
    {
        cout << sentence << endl;
    }

    return 0;
}
