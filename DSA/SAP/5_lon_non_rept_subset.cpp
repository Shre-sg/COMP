#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest
// substring
//  without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// set approach
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++)
        {
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// unordered map approach

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLength = 0;
//         int left = 0;
//         unordered_map<char, int> lastSeen;

//         for (int right = 0; right < s.length(); right++) {
//             char c = s[right];
//             if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
//                 left = lastSeen[c] + 1;
//             }
//             maxLength = max(maxLength, right - left + 1);
//             lastSeen[c] = right;
//         }

//         return maxLength;
//     }
// };

int main()
{
    Solution solution;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = solution.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
