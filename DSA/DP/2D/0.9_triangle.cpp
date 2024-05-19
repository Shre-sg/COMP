// 120. Triangle
// Solved
// Medium
// Topics
// Companies
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
// 2
// 3 4
// 6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:
// Input: triangle = [[-10]]
// Output: -10

// Constraints:
// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104

// striver
//  Minimum path sum in Triangular Grid (DP 11)
//  In this article, we will solve the most asked coding interview problem: Minimum path sum in Triangular Grid
//  Problem Link: Fixed Starting and Ending Point
//  Problem Description:
//  We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.
//  At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == n - 1)
            return triangle[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // TABULATION approach
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];

        // return f(0, 0, triangle, n, dp); // This is the recursive with memoization approach
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    int result = sol.minimumTotal(triangle);
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}
