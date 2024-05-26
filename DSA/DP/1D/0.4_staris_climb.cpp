// 70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:

// 1 <= n <= 45

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int f(vector<int> &dp, int n)
    {
        if (dp[n] != -1)
            return dp[n];

        if (n == 0)
            return 1;

        if (n == 1)
            return 1;

        dp[n] = f(dp, n - 1) + f(dp, n - 2);
        return dp[n];
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(dp, n);
    }
};

// Example usage
int main()
{
    Solution sol;
    int n = 2;
    cout << sol.climbStairs(n) << endl; // Output: 2

    n = 3;
    cout << sol.climbStairs(n) << endl; // Output: 3

    return 0;
}

// tablulation approach
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 3;
    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}

// optamised approach
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 3;

    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}