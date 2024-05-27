#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 402. Remove K Digits

// Given string num representing a non-negative integer num, and an integer k, return the smallest
/// possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;

        // If the number of digits to remove is equal to the length of num, return "0"
        if (num.size() == k)
            return "0";

        // Iterate through each digit in num
        for (auto iter : num)
        {
            // While the stack is not empty, the current digit is less than the top of the stack,
            // and there are still digits to remove (k > 0), pop elements from the stack
            while (!st.empty() && iter < st.top() && k > 0)
            {
                k--;
                st.pop();
            }
            // Push the current digit onto the stack
            st.push(iter);
        }

        // After removing k digits, if there are still digits to remove, pop them from the stack
        while (k > 0)
        {
            st.pop();
            k--;
        }

        // Construct the result string from the remaining elements in the stack
        int n = st.size();
        string ans;
        while (st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }

        // Reverse the result string to get the correct order of digits
        reverse(ans.begin(), ans.end());

        // Remove leading zeros from the result string
        int i = 0;
        while (i < n && ans[i] == '0')
            i++;

        // Construct the final result string after removing leading zeros
        string result;
        for (int j = i; j < n; j++)
        {
            result += ans[j];
        }
        // If the final result string is empty, return "0"
        if (result.size() == 0)
            return "0";
        // Otherwise, return the final result string
        return result;
    }
};

int main()
{
    Solution solution;
    string num = "1432219";
    int k = 3;
    cout << "Original number: " << num << endl;
    cout << "Number after removing " << k << " digits: " << solution.removeKdigits(num, k) << endl;
    return 0;
}
