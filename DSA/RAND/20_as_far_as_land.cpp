// 1162. As Far from Land as Possible

// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Example 1:

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:

// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));

        // Enqueue all land cells and mark them as visited
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // If there are no land cells or the grid is full of land cells, return -1
        if (q.empty())
            return -1;
        if (q.size() == n * m)
            return -1;

        int maxi = INT_MIN;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int dist = it.second;

            maxi = max(dist, maxi);

            int r[] = {-1, 0, 1, 0};
            int c[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++)
            {
                int row = i + r[k];
                int col = j + c[k];

                if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 0 && vis[row][col] == -1)
                {
                    vis[row][col] = 1;
                    q.push({{row, col}, dist + 1});
                }
            }
        }
        return maxi;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}};

    int result = sol.maxDistance(grid);
    cout << "The maximum distance from land to water is: " << result << endl;

    return 0;
}
