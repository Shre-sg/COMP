// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200

// STRIVER
//  Minimum Path Sum In a Grid (DP 10)
//  In this article, we will solve the most asked coding interview problem: Minimum Path Sum In a Grid.

// Problem Link: Minimum Path Sum in A Grid
// Problem Description:
// We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.
// At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.

// memorizattion

#include <bits/stdc++.h>
using namespace std;

// Helper function to find the minimum sum path from (i, j) to (0, 0) in the matrix
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)

    if (i < 0 || j < 0)
        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path

    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));   // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}

int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}

// tabu;ation

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else
            {
                int up = matrix[i][j]; // that ele + prev
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
