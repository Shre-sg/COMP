#include <iostream>
#include <string>

using namespace std;
// u can only append

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return t.length() - j;
    }
};

int main()
{
    Solution solution;

    string s1 = "abcde";
    string t1 = "ace";
    cout << "Result for s1 and t1: " << solution.appendCharacters(s1, t1) << endl;

    string s2 = "abc";
    string t2 = "abcde";
    cout << "Result for s2 and t2: " << solution.appendCharacters(s2, t2) << endl;

    string s3 = "abcdef";
    string t3 = "fbd";
    cout << "Result for s3 and t3: " << solution.appendCharacters(s3, t3) << endl;

    string s4 = "xyz";
    string t4 = "xyz";
    cout << "Result for s4 and t4: " << solution.appendCharacters(s4, t4) << endl;

    string s5 = "abcdefgh";
    string t5 = "hgf";
    cout << "Result for s5 and t5: " << solution.appendCharacters(s5, t5) << endl;

    return 0;
}
