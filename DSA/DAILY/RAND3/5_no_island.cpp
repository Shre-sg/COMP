// 200. Number of Islands
// Solved
// Medium
// Topics
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // boundary checking
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        // return if current position is water or already visited
        if (grid[i][j] == '2' || grid[i][j] == '0')
            return;

        // mark the current as visited
        grid[i][j] = '2';

        // do DFS in all 4 directions
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        // We make each 1 as 2 when it is visited
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // do DFS if it has not been visited and there is land
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution sol;
    int islands = sol.numIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}
