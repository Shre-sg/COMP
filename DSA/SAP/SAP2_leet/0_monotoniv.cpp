#include <iostream>
#include <string>
using namespace std;

// 738. Monotone Increasing Digits
// Solved
// Medium
// Topics
// Companies
// Hint
// An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

// Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

// Example 1:

// Input: n = 10
// Output: 9
// Example 2:

// Input: n = 1234
// Output: 1234
// Example 3:

// Input: n = 332
// Output: 299

// Constraints:

// 0 <= n <= 109

// Intuition
// Suppose we have a non-negative integer N, we have to find the largest number that is less than or equal to N with monotone increasing digits. We know that an integer has monotone increasing digits if and only if each pair of adjacent digits’ x and y satisfy x <= y.) So if the input is like 332, then the result will be 299.

// To solve this, we will follow these steps −

// s := N as string, i := 1, n := size of s
// while i < n and s[i] >= s[i – 1]
// increase i by 1
// if i < n
// while i > 0 and s[i – 1] > s[i], then
// decrease i by 1
// decrease s[i] by 1
// for j in range i + 1 to n
// s[j] := ‘9’
// return s as number

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string ag = to_string(n);

        int i = 1;
        // Find the first position where the current digit is less than the previous digit
        while (i < ag.size() && ag[i] >= ag[i - 1])
        {
            i++;
        }
        // Move back to adjust the digits to ensure monotone increasing
        while (i > 0 && i < ag.size() && ag[i - 1] > ag[i])
        {
            ag[i - 1]--;
            i--;
        }
        // Set all digits after the adjusted position to '9'
        for (int j = i + 1; j < ag.size(); j++)
        {
            ag[j] = '9';
        }
        return stoi(ag);
    }
};

int main()
{
    Solution sol;

    // Example usage:
    int input1 = 1234;
    int input2 = 332;

    cout << "Monotone increasing digits of " << input1 << ": " << sol.monotoneIncreasingDigits(input1) << endl;
    cout << "Monotone increasing digits of " << input2 << ": " << sol.monotoneIncreasingDigits(input2) << endl;

    return 0;
}
