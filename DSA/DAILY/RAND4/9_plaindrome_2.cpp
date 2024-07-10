#include <string>
using namespace std;

// 680. Valid Palindrome II

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (int st = 0, e = s.size() - 1; st < e; st++, e--)
        {
            if (s[st] != s[e])
            {
                int i1 = st, j1 = e - 1, i2 = st + 1, j2 = e;
                while (i1 < j1 && s[i1] == s[j1])
                {
                    i1++;
                    j1--;
                }
                while (i2 < j2 && s[i2] == s[j2])
                {
                    i2++;
                    j2--;
                }
                return (i1 >= j1 || i2 >= j2);
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    // Example usage:
    string input1 = "aba";
    string input2 = "abca";

    cout << "Is '" << input1 << "' a valid palindrome (allowing at most one removal)? "
         << (sol.validPalindrome(input1) ? "Yes" : "No") << endl;

    cout << "Is '" << input2 << "' a valid palindrome (allowing at most one removal)? "
         << (sol.validPalindrome(input2) ? "Yes" : "No") << endl;

    return 0;
}
