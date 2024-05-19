// 931. Minimum Falling Path Sum

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:

// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:

// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

// striver
//  Minimum/Maximum Falling Path Sum (DP-12)

// In this article, we will solve the most asked coding interview problem: Minimum/Maximum falling path sum.
// Problem Link: Variable Starting and Ending Point
// Problem Description:
// We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.
// At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // Base Conditions
        if (j < 0 || j >= m)
            return 1e9; // A very large value to represent an invalid path

        if (i == 0)
            return matrix[0][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
        int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Uncomment for memoization approach
        // int maxi = INT_MAX; // Initialize the maximum path sum to a very large value
        // for (int j = 0; j < m; j++) {
        //     int ans = getMaxUtil(n - 1, j, m, matrix, dp);
        //     maxi = min(maxi, ans);
        // }
        // return maxi; // Return the maximum path sum

        // TABULAION
        //  Initialize the first row of dp with the first row of the matrix
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        // Iterate through the matrix rows starting from the second row
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + dp[i - 1][j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0)
                {
                    leftDiagonal += dp[i - 1][j - 1];
                }
                else
                {
                    leftDiagonal += 1e9; // A very large value to represent an invalid path
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m)
                {
                    rightDiagonal += dp[i - 1][j + 1];
                }
                else
                {
                    rightDiagonal += 1e9; // A very large value to represent an invalid path
                }

                // Store the minimum of the three paths in dp
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        // Find the minimum value in the last row of dp, which represents the minimum path sums ending at each cell
        int mini = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        // The minimum path sum is the minimum value in the last row
        return mini;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};

    int result = sol.minFallingPathSum(matrix);
    cout << "The minimum falling path sum is: " << result << endl;

    return 0;
}
