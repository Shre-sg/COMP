#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// 127. Word Ladder     striver vid

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a
// sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in
// the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

class Solution
{
public:
    // Original version
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        set<string> st, words;

        for (string s : wordList)
            words.insert(s);

        st.insert(beginWord);
        q.push(beginWord);
        int res = 0;

        while (q.size())
        {
            int n = q.size();
            res++;
            for (int i = 0; i < n; i++)
            {
                string s = q.front();

                if (s == endWord)
                    return res;

                q.pop();
                string t;
                for (int i = 0; i < s.size(); i++)
                {
                    t = s;
                    for (int j = 'a'; j <= 'z'; j++)
                    {
                        t[i] = j;
                        if (words.count(t) and !st.count(t))
                        {
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }

    // Optimized version
    int ladderLength(string s, string t, vector<string> &w)
    {
        set<string> st;
        for (int i = 0; i < w.size(); i++)
        {
            st.insert(w[i]);
        }
        queue<pair<string, int>> q;
        q.push({s, 0});
        st.erase(s);
        while (!q.empty())
        {
            auto curr = q.front();
            string str = curr.first;
            int d = curr.second;
            q.pop();
            if (str == t)
                return d + 1;
            for (int i = 0; i < str.length(); i++)
            {
                string t = str;
                for (char it = 'a'; it <= 'z'; it++)
                {
                    t[i] = it;
                    if (st.count(t))
                    {
                        st.erase(t);
                        q.push({t, d + 1});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    // Example usage
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution sol;

    // Using original version
    int minStepsOriginal = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Minimum steps using original version: " << minStepsOriginal << endl;

    // Using optimized version
    int minStepsOptimized = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Minimum steps using optimized version: " << minStepsOptimized << endl;

    return 0;
}
