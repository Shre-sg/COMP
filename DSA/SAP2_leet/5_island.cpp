#include <iostream>
#include <vector>
using namespace std;

// 200. Number of Islands

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

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis)
    {
        vis[n][m] = 1;
        int trow = grid.size(); // for validation checking
        int tcol = grid[0].size();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = n + i;
                int ncol = m + j;
                if (nrow >= 0 && nrow < trow && ncol >= 0 && ncol < tcol && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    dfs(grid, nrow, ncol, vis);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == '1')
                {
                    dfs(grid, i, j, vis);
                    cnt++;
                }
            }
        }
        return cnt;
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

// USING BFS
//  void bfs(vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis)
//  {
//      vis[n][m] = 1;
//      int trow = grid.size();
//      int tcol = grid[0].size();
//      queue<pair<int, int>> q;
//      q.push({n, m});
//      while (!q.empty())
//      {
//          int row = q.front().first;
//          int col = q.front().second;
//          q.pop();
//          for (int i = -1; i <= 1; i++)
//          {
//              for (int j = -1; j <= 1; j++)
//              {
//                  int nrow = row + i;
//                  int ncol = col + j;
//                  if (nrow >= 0 && nrow < trow && ncol >= 0 && ncol < tcol && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
//                  {
//                      vis[nrow][ncol] = 1;
//                      q.push({nrow, ncol});
//                  }
//              }
//          }
//      }
//  }

// // Function to find the number of islands.
// int numIslands(vector<vector<char>> &grid)
// {
//     // Code here
//     int cnt = 0;
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> vis(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (vis[i][j] == 0 && grid[i][j] == '1')
//             {
//                 bfs(grid, i, j, vis);
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

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
        // return if current position is of water or is already visited
        if (grid[i][j] == '2' || grid[i][j] == '0')
            return;
        // mark it as visited
        grid[i][j] = '2';

        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
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