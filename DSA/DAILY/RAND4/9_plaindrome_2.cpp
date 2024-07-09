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
                if (i1 >= j1 || i2 >= j2)
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};
