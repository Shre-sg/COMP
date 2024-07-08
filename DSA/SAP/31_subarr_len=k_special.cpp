// Find length of longest substring with at most K normal characters
// Last Updated : 02 Aug, 2023
// Given a string P consisting of small English letters and a 26-digit bit string Q, where 1 represents the special character and 0 represents a normal character for the 26 English alphabets. The task is to find the length of the longest substring with at most K normal characters.

// Examples:

// Input : P = “normal”, Q = “00000000000000000000000000”, K=1
// Output : 1
// Explanation : In string Q all characters are normal.
// Hence, we can select any substring of length 1.

// Input : P = “giraffe”, Q = “01111001111111111011111111”, K=2
// Output : 3
// Explanation : Normal characters in P from Q are {a, f, g, r}.
// Therefore, possible substrings with at most 2 normal characters are {gir, ira, ffe}.
// The maximum length of all substring is 3.

// Recommended: Please try your approach on {IDE} first, before moving on to the solution.
// Approach:
// To solve the problem mentioned above we will be using the concept of two pointers. Hence, maintain left and right pointers of the substring, and a count of normal characters. Increment the right index till the count of normal characters is at most K. Then update the answer with a maximum length of substring encountered till now. Increment left index and decrement count till it is greater than K.
// Below is the implementation of the above approach:

// brute
// C++ implementation to Find
// length of longest substring
// with at most K normal characters
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// length of normal substrings
int maxNormalSubstring(string &P, string &Q,
                       int K, int N)
{

    if (K == 0)
        return 0;

    // keeps count of normal characters
    int count = 0;

    // indexes of substring
    int left = 0, right = 0;

    // maintain length of longest substring
    // with at most K normal characters
    int ans = 0;

    while (right < N)
    {

        while (right < N && count <= K)
        {
            // get position of character
            int pos = P[right] - 'a';
            // check if current character is normal
            if (Q[pos] == '0')
            {
                // check if normal characters// count exceeds K
                if (count + 1 > K)
                    break;
                else
                    count++;
            }
            right++;
            // update answer with substring length
            if (count <= K)
                ans = max(ans, right - left);
        }
        while (left < right)
        {
            // get position of character
            int pos = P[left] - 'a';
            left++;
            // check if character is// normal then decrement count
            if (Q[pos] == '0')
                count--;
            if (count < K)
                break;
        }
    }

    return ans;
}

// Driver code
int main()
{
    // initialise the string
    string P = "giraffe", Q = "01111001111111111011111111";

    int K = 2;

    int N = P.length();

    cout << maxNormalSubstring(P, Q, K, N);

    return 0;
}
