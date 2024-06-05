#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1002. Find Common Characters

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

class Solution
{
public:
    vector<string> commonChars(vector<string> &arr)
    {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        // Fill hash1 with the frequency of each character in the first string
        for (auto ch : arr[0])
        {
            hash1[ch - 'a']++;
        }

        // Process each subsequent string
        for (int i = 1; i < arr.size(); i++)
        {
            for (auto ch : arr[i])
            {
                hash2[ch - 'a']++;
            }

            // Update hash1 to keep only the minimum frequency counts
            for (int j = 0; j < 26; j++)
            {
                hash1[j] = min(hash1[j], hash2[j]);
                hash2[j] = 0; // Reset hash2 for the next string
            }
        }

        // Collect the common characters
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            if (hash1[i] > 0)
            {
                int count = hash1[i];
                while (count--)
                {
                    char x = i + 'a';
                    string s(1, x); // Create a string with the character x
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> arr = {"bella", "label", "roller"};
    vector<string> result = sol.commonChars(arr);

    cout << "Common characters are: ";
    for (string s : result)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
