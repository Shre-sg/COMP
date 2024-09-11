// 1663. Smallest String With A Given Numeric Value
// Medium
// Topics
// Companies
// Hint
// The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

// The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

// You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

// Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

// Example 1:

// Input: n = 3, k = 27
// Output: "aay"
// Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
// Example 2:

// Input: n = 5, k = 73
// Output: "aaszz"

// Constraints:

// 1 <= n <= 105
// n <= k <= 26 * n

// Certainly! Let's go through the explanation in detail, focusing on how you build a string based on a given sum
// 𝐾
// K, ensuring that the string is lexicographically ordered and that its characters add up to
// 𝐾
// K.

// Objective
// You want to construct a string of length
// 𝑁
// N where the sum of the character values equals
// 𝐾
// K. Each character is valued from 1 (for 'a') to 26 (for 'z').

// Key Points in the Formula
// Adding 'a':

// Condition: You can keep adding 'a' to the string as long as
// 𝐾
// K can be satisfied by the remaining positions in the string. This is checked using:

// 𝐾
// ≤
// (
// 𝑁
// −
// 1
// )
// ×
// 26
// K≤(N−1)×26
// Here:

// 𝑁
// N is the number of remaining positions in the string.
// 26 is the maximum contribution of any character ('z').
// Reasoning: If
// 𝐾
// K is less than or equal to the maximum possible sum with the remaining positions (i.e., all remaining characters being 'z'), you can safely use 'a' for the current position because the remaining characters can still meet the required sum.

// Adding a Different Character:

// When to Use: When
// 𝐾
// K is not small enough to be satisfied by 'a' in the remaining positions, you need to use a character other than 'a'.

// Calculation of Character: The value of the character to add is calculated using:

// ch
// =
// 𝐾
// −
// (
// 𝑁
// −
// 1
// )
// ×
// 26
// ch=K−(N−1)×26
// This formula determines how much value you need to contribute with the current character to achieve
// 𝐾
// K, considering that the remaining characters (after the current one) can be anything from 'a' to 'z'.

// Example: If you have
// 𝐾
// =
// 30
// K=30 and
// 𝑁
// =
// 3
// N=3:

// For the last position, you can only use 'a' since there’s no remaining position to satisfy any additional sum.
// For the second position, you calculate:
// ch
// =
// 30
// −
// (
// 1
// ×
// 26
// )
// =
// 30
// −
// 26
// =
// 4
// ch=30−(1×26)=30−26=4
// This means the second-to-last position should be a character with a value of 4, which corresponds to 'd'.
// For the first position, you would then adjust based on the remaining sum needed.
// Constructing the String Step-by-Step
// Initialize Variables:

// Start with an empty string.
// Set the initial sum
// 𝐾
// K and the number of positions
// 𝑁
// N.
// Iterate Over Positions:

// For each position from left to right:
// Check if Adding 'a': If
// 𝐾
// ≤
// (
// 𝑁
// −
// 1
// )
// ×
// 26
// K≤(N−1)×26, add 'a' to the string. Decrease
// 𝑁
// N by 1.
// Add Appropriate Character:
// Calculate the character value using
// ch
// =
// 𝐾
// −
// (
// 𝑁
// −
// 1
// )
// ×
// 26
// ch=K−(N−1)×26.
// Append the corresponding character to the string.
// Adjust
// 𝐾
// K and
// 𝑁
// N accordingly.
// Finalize the String:

// After iterating through all positions, ensure the string is complete and the sum of its characters equals
// 𝐾
// K.
// Example Breakdown
// Given:

// 𝐾
// =
// 30
// K=30
// 𝑁
// =
// 3
// N=3
// Steps:

// First Position:

// Maximum sum with remaining 2 positions:
// 2
// ×
// 26
// =
// 52
// 2×26=52
// Since
// 30
// ≤
// 52
// 30≤52, add 'a'. Adjust
// 𝐾
// K to
// 30
// −
// 1
// =
// 29
// 30−1=29, and
// 𝑁
// N to 2.
// Second Position:

// Maximum sum with remaining 1 position:
// 1
// ×
// 26
// =
// 26
// 1×26=26
// Since
// 29
// >
// 26
// 29>26, use the character calculated by:
// ch
// =
// 29
// −
// 26
// =
// 3
// ch=29−26=3
// Character 'c' has a value of 3. Append 'c' to the string. Adjust
// 𝐾
// K to
// 29
// −
// 3
// =
// 26
// 29−3=26, and
// 𝑁
// N to 1.
// Third Position:

// Since it's the last position, fill in with the character that equals the remaining sum
// 𝐾
// K:
// The remaining sum
// 𝐾
// K is 26, which corresponds to 'z'.
// Final String: "acb"

// This method ensures that the string is both lexicographically ordered and correctly sums up to
// 𝐾
// K.

// https://chatgpt.com/c/66dc0d17-3fd4-8001-9dd6-a88ac661ef7f

#include <iostream>
#include <string>

using namespace std;

string constructString(int N, int K)
{
    string result;

    // Iterate over each position from left to right
    while (N > 0)
    {
        // Calculate the maximum sum possible with the remaining positions
        int maxSumRemaining = (N - 1) * 26;

        if (K <= maxSumRemaining)
        {
            // Add 'a' if K can be satisfied with remaining positions
            result += 'a';
            K -= 1; // Reduce K by 1 (value of 'a')
        }
        else
        {
            // Calculate the value of the character to add
            int charValue = K - maxSumRemaining;
            // Append the corresponding character
            result += (char)('a' + charValue - 1);
            // Reduce K by the value of this character
            K -= charValue;
        }

        // Reduce the number of remaining positions
        N -= 1;
    }

    return result;
}

int main()
{
    int N = 3;  // Length of the string
    int K = 30; // Sum of character values

    string result = constructString(N, K);
    cout << "Constructed String: " << result << endl;

    return 0;
}
