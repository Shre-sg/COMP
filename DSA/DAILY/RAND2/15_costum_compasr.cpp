#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 3170. Lexicographically Minimum String After Removing Stars

// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the
// lexicographically smallest
//  resulting string after removing all '*' characters.

// Example 1:

// Input: s = "aaba*"

// Output: "aab"

// Explanation:

// We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

// Example 2:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no '*' in the string.

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters and '*'.
// The input is generated such that it is possible to delete all '*' characters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 19K
// Submissions
// 57.3K
// Acceptance Rate
// 33.2%

class Solution
{
public:
    string clearStars(string s)
    {
        // Custom comparator for the priority queue
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second < b.second; // Higher index has higher priority
            return a.first > b.first;       // Smaller character value has higher priority
        };

        // Priority queue to store pairs of characters and their indices
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        string result = "";

        // Iterate over the string
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '*')
            {
                // If current character is not '*', push it and its index to the priority queue
                pq.push({s[i], i});
            }
            else
            {
                // If current character is '*', replace the character at the smallest index with '*'
                s[pq.top().second] = '*';
                pq.pop();
            }
        }

        // Print the modified string after processing for debugging purposes
        cout << s << endl;

        // Build the result string, excluding '*' characters
        for (char c : s)
        {
            if (c != '*')
            {
                result += c;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string input = "aaba*";
    string output = sol.clearStars(input);
    cout << "Output: " << output << endl; // Output: "aab"
    return 0;
}
