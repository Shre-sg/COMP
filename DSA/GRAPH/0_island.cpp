#include <iostream>
#include <vector>
using namespace std;

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