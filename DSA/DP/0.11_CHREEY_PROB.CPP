// 741. Cherry Pickup
// You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through,
// 1 means the cell contains a cherry that you can pick up and pass through, or
// -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by following the rules below:

// Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
// After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
// When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
// If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

// Example 1:

// Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
// Output: 5
// Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.
// Example 2:

// Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
// Output: 0

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// grid[i][j] is -1, 0, or 1.
// grid[0][0] != -1
// grid[n - 1][n - 1] != -1

// STRIVER
//  3-d DP : Ninja and his friends (DP-13)

// In this article, we will solve the most asked coding interview problem: Ninja and his friends.
// Problem Link: Ninja and his friends
// Problem Description:
// We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

// When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.

// They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.

// STRIVER

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum chocolates that can be collected recursively
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // Check if the positions (j1, j2) are valid
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9; // A very large negative value to represent an invalid position

    // Base case: If we are at the last row, return the chocolate at the positions (j1, j2)
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // If the result for this state is already computed, return it
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;

    // Try all possible moves (up, left, right) for both positions (j1, j2)
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;

            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);

            // Update the maximum result
            maxi = max(maxi, ans);
        }
    }

    // Store the maximum result for this state in dp
    return dp[i][j1][j2] = maxi;
}

// Function to find the maximum chocolates that can be collected
int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // Call the recursive utility function to find the maximum chocolates starting from the first row
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

int main()
{
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}

// LEETCODE
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2, int n, vector<vector<vector<int>>> &dp)
    {
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;
        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1];
            cherries += grid[r2][c2];
        }

        int f1 = solve(grid, r1, c1 + 1, r2, c2 + 1, n, dp);
        int f2 = solve(grid, r1 + 1, c1, r2, c2 + 1, n, dp);
        int f3 = solve(grid, r1 + 1, c1, r2 + 1, c2, n, dp);
        int f4 = solve(grid, r1, c1 + 1, r2 + 1, c2, n, dp);

        cherries += max({f1, f2, f3, f4});
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        int ans = solve(grid, 0, 0, 0, 0, n, dp);
        return max(0, ans);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}};

    int result = sol.cherryPickup(grid);
    cout << "The maximum number of chocolates collected is: " << result << endl;

    return 0;
}
