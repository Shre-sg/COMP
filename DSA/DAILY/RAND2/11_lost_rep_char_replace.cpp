// 424. Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> alphabets;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;

        for (right = 0; right < s.size(); right++)
        {
            alphabets[s[right]]++;
            maxf = max(maxf, alphabets[s[right]]);

            if ((right - left + 1) - maxf > k)
            {
                alphabets[s[left]]--;
                left++;
            }
            else
            {
                ans = max(ans, (right - left + 1)); // max length
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "AABABBA";
    int k = 1;
    cout << "The length of the longest substring after at most " << k << " replacements is: " << solution.characterReplacement(s, k) << endl;
    return 0;
}
