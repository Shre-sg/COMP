#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canFormPalindrome(const string &s)
{
    // Create an unordered map to store the frequency of each character
    unordered_map<char, int> charCount;

    // Count the frequency of each character in the string
    for (char ch : s)
    {
        charCount[ch]++;
    }

    // Count how many characters have an odd frequency
    int oddCount = 0;
    for (const auto &entry : charCount)
    {
        if (entry.second % 2 != 0)
        {
            oddCount++;
        }
    }

    // A string can form a palindrome if it has at most one odd character count
    return oddCount <= 1;
}

int main()
{
    string s1 = "civic";
    string s2 = "ivicc";
    string s3 = "hello";

    cout << boolalpha; // to print bool values as true/false

    cout << "Can \"" << s1 << "\" be rearranged to form a palindrome? "
         << canFormPalindrome(s1) << endl;
    cout << "Can \"" << s2 << "\" be rearranged to form a palindrome? "
         << canFormPalindrome(s2) << endl;
    cout << "Can \"" << s3 << "\" be rearranged to form a palindrome? "
         << canFormPalindrome(s3) << endl;

    return 0;
}
