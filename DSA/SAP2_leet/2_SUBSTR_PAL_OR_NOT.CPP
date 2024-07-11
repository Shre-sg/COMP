#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1177. Can Make Palindrome from Substring

// You are given a string s and array queries where queries[i] = [lefti, righti, ki]. We may rearrange the substring s[lefti...righti] for each query and then choose up to ki of them to replace with any lowercase English letter.

// If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.

// Return a boolean array answer where answer[i] is the result of the ith query queries[i].

// Note that each letter is counted individually for replacement, so if, for example s[lefti...righti] = "aaa", and ki = 2, we can only replace two of the letters. Also, note that no query modifies the initial string s.

// Example :

// Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
// Output: [true,false,false,true,true]
// Explanation:
// queries[0]: substring = "d", is palidrome.
// queries[1]: substring = "bc", is not palidrome.
// queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
// queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
// queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.
// Example 2:

// Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
// Output: [false,true]

// Constraints:

// 1 <= s.length, queries.length <= 105
// 0 <= lefti <= righti < s.length
// 0 <= ki <= s.length
// s consists of lowercase English letters.

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        // Prefix vector to store counts of each character up to each position in the string
        vector<vector<int>> prefixCounts;

        // Initialize the prefixCounts with a vector of 26 zeros (for each letter of the alphabet)
        vector<int> currentCount(26, 0);
        prefixCounts.push_back(currentCount);

        // Fill the prefix vector with counts of each character
        for (char c : s)
        {
            currentCount[c - 'a']++;
            prefixCounts.push_back(currentCount);
        }

        // Result vector to store answers for each query
        vector<bool> results;

        // Process each query
        for (const auto &query : queries)
        {
            int left = query[0], right = query[1], k = query[2];
            vector<int> charCounts = prefixCounts[right + 1];

            // Calculate the count of each character in the substring [left, right]
            for (int i = 0; i < 26; i++)
            {
                charCounts[i] -= prefixCounts[left][i];
            }

            // Count the number of characters that appear an odd number of times
            int oddCount = 0;
            for (int count : charCounts)
            {
                if (count % 2 != 0)
                {
                    oddCount++;
                }
            }

            // We can make at most oddCount / 2 replacements to make the string a palindrome
            results.push_back(oddCount / 2 <= k);
        }

        return results;
    }
};

int main()
{
    Solution solution;
    string s = "abcda";
    vector<vector<int>> queries = {
        {0, 4, 1},
        {1, 2, 0},
        {0, 3, 1},
        {2, 4, 0}};

    vector<bool> results = solution.canMakePaliQueries(s, queries);

    for (bool result : results)
    {
        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}
