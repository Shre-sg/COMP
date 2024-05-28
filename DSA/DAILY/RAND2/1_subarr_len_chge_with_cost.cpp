// 1208. Get Equal Substrings Within Budget

// You are given two strings s and t of the same length and an integer maxCost.

// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

// Example 1:

// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
// Explanation: "abc" of s can change to "bcd".
// That costs 3, so the maximum length is 3.
// Example 2:

// Input: s = "abcd", t = "cdef", maxCost = 3
// Output: 1
// Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
// Example 3:

// Input: s = "abcd", t = "acde", maxCost = 0
// Output: 1
// Explanation: You cannot make any change, so the maximum length is 1.

// Constraints:

// 1 <= s.length <= 105
// t.length == s.length
// 0 <= maxCost <= 106
// s and t consist of only lowercase English letters.

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size(), i = 0, ans = -1e9, j = 0, cost = 0;
        while (j < n)
        {
            cost += abs(t[j] - s[j]);
            while (i < n && cost > maxCost)
            {
                cost -= abs(t[i] - s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;

    int result = solution.equalSubstring(s, t, maxCost);
    cout << "Maximum length of a substring that can be made equal: " << result << endl;

    return 0;
}
