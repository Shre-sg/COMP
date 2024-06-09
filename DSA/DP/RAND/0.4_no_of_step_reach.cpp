// 2400. Number of Ways to Reach a Position After Exactly k Steps
// Solved

// You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

// Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

// Two ways are considered different if the order of the steps made is not exactly the same.

// Note that the number line includes negative integers.

// Example 1:

// Input: startPos = 1, endPos = 2, k = 3
// Output: 3
// Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
// - 1 -> 2 -> 3 -> 2.
// - 1 -> 2 -> 1 -> 2.
// - 1 -> 0 -> 1 -> 2.
// It can be proven that no other way is possible, so we return 3.
// Example 2:

// Input: startPos = 2, endPos = 5, k = 10
// Output: 0
// Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.

// Constraints:

// 1 <= startPos, endPos, k <= 1000

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int mod = (int)1e9 + 7;

    int solve(vector<vector<int>> &dp, int startPos, int endPos, int k)
    {
        // Base condition
        if (k == 0)
        {
            return startPos == endPos ? 1 : 0;
        }

        if (dp[startPos + 1000][k] != -1)
        {
            return dp[startPos + 1000][k]; // If already visited
        }

        int a = solve(dp, startPos + 1, endPos, k - 1) % mod; // Step forward
        int b = solve(dp, startPos - 1, endPos, k - 1) % mod; // Step backward

        return dp[startPos + 1000][k] = (a + b) % mod; // Store in dp (memoize)
    }

    int numberOfWays(int startPos, int endPos, int k)
    {
        vector<vector<int>> dp(3001, vector<int>(k + 1, -1));
        return solve(dp, startPos, endPos, k);
    }
};

int main()
{
    // Test case
    int startPos = 1;
    int endPos = 2;
    int k = 3;

    // Create a Solution object
    Solution solution;

    // Call the numberOfWays function and print the result
    int result = solution.numberOfWays(startPos, endPos, k);
    cout << "Number of ways to reach " << endPos << " from " << startPos << " in " << k << " steps is: " << result << endl;

    return 0;
}

// recurssion
class Solution
{
public:
    int solve(int startPos, int endPos, int k)
    {
        // Base Condn
        if (k == 0)
        {
            if (startPos == endPos)
                return 1; // If we reach the endpos in k steps
            else
                return 0;
        }

        int a = solve(startPos + 1, endPos, k - 1); // Step Forward
        int b = solve(startPos - 1, endPos, k - 1); // Step Backward

        return (a + b); // Return total ways
    }

    int numberOfWays(int startPos, int endPos, int k)
    {
        return solve(startPos, endPos, k);
    }
};