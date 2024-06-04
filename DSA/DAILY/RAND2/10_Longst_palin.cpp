// 409. Longest Palindrome

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest
// palindrome
//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int oddFrequencyCount = 0;
        unordered_map<char, int> charFrequency;
        for (char ch : s)
        {
            charFrequency[ch]++;
            if (charFrequency[ch] % 2 == 1)
                oddFrequencyCount++;
            else
                oddFrequencyCount--;
        }
        if (oddFrequencyCount > 1)
            return s.length() - oddFrequencyCount + 1;
        return s.length();
    }
};

int main()
{
    Solution solution;
    string s = "abccccdd";
    cout << "The length of the longest palindrome that can be built is: " << solution.longestPalindrome(s) << endl;
    return 0;
}
