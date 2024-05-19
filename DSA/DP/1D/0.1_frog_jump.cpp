// Problem Statement:
// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int jumpTwo = INT_MAX;

    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n + 1, -1);
    cout << solve(n - 1, height, dp);
}

// // tabulation

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

//     vector<int> height{30, 10, 60, 10, 60, 50};
//     int n = height.size();
//     vector<int> dp(n, -1);
//     dp[0] = 0;
//     for (int ind = 1; ind < n; ind++)
//     {
//         int jumpTwo = INT_MAX;
//         int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
//         if (ind > 1)
//             jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

//         dp[ind] = min(jumpOne, jumpTwo);
//     }
//     cout << dp[n - 1];
// }

// /// optimization

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> height{30, 10, 60, 10, 60, 50};
//     int n = height.size();
//     int prev = 0;
//     int prev2 = 0;
//     for (int i = 1; i < n; i++)
//     {

//         int jumpTwo = INT_MAX;
//         int jumpOne = prev + abs(height[i] - height[i - 1]);
//         if (i > 1)
//             jumpTwo = prev2 + abs(height[i] - height[i - 2]);

//         int cur_i = min(jumpOne, jumpTwo);
//         prev2 = prev;
//         prev = cur_i;
//     }
//     cout << prev;
// }
