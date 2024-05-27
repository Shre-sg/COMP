// 1219. Path with Maximum Gold
// Solved
// Medium
// Topics
// Companies
// Hint
// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.

// Example 1:

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.
// Example 2:

// Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// Output: 28
// Explanation:
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 15
// 0 <= grid[i][j] <= 100
// There are at most 25 cells containing gold.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int DFS(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int sum)
    {
        int n = mat.size();
        int m = mat[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || mat[i][j] == 0)
        {
            return sum;
        }

        visited[i][j] = true;
        sum += mat[i][j];

        int maxGold = sum;

        maxGold = max(maxGold, DFS(mat, visited, i + 1, j, sum));
        maxGold = max(maxGold, DFS(mat, visited, i - 1, j, sum));
        maxGold = max(maxGold, DFS(mat, visited, i, j + 1, sum));
        maxGold = max(maxGold, DFS(mat, visited, i, j - 1, sum));

        visited[i][j] = false;
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxGold = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 0)
                {
                    maxGold = max(maxGold, DFS(grid, visited, i, j, 0));
                }
            }
        }

        return maxGold;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}};

    cout << "Maximum gold: " << sol.getMaximumGold(grid) << endl;

    return 0;
}
