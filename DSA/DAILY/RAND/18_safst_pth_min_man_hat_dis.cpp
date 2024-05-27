#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 2812. Find the Safest Path in a Grid

// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

// The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

// Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

// The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

// Example 1:

// Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
// Output: 0
// Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
// Example 2:

// Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
// Output: 2
// Explanation: The path depicted in the picture above has a safeness factor of 2 since:
// - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
// It can be shown that there are no other paths with a higher safeness factor.
// Example 3:

// Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
// Output: 2
// Explanation: The path depicted in the picture above has a safeness factor of 2 since:
// - The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
// - The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
// It can be shown that there are no other paths with a higher safeness factor.

// Constraints:

// 1 <= grid.length == n <= 400
// grid[i].length == n
// grid[i][j] is either 0 or 1.
// There is at least one thief in the grid.

class Solution
{
public:
    int n;

    // Check if coordinates are valid within the grid boundaries
    bool valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    // Check if coordinates are valid within the grid boundaries
    bool isValid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    // Function to compute the minimum distance grid
    vector<vector<int>> computeDistanceGrid(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> distGrid(n, vector<int>(n, INT_MAX)); // Initialize with maximum value
        queue<pair<int, int>> q;

        // Initialize the queue and distance for '0' cells
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    distGrid[i][j] = 0;
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS to compute minimum distances
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (isValid(newX, newY, n) && distGrid[newX][newY] == INT_MAX)
                {
                    distGrid[newX][newY] = distGrid[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return distGrid;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        n = grid.size();
        if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1)
            return 0;

        vector<vector<int>> dist = computeDistanceGrid(grid);
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<int> delr = {-1, 0, 1, 0};
        vector<int> delc = {0, 1, 0, -1};

        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int ds = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if (i == n - 1 && j == n - 1)
                return ds;

            for (int l = 0; l < 4; ++l)
            {
                int nrow = i + delr[l];
                int ncol = j + delc[l];
                if (valid(nrow, ncol) && grid[nrow][ncol] != 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    int ds1 = dist[nrow][ncol];
                    pq.push({min(ds, ds1), {nrow, ncol}});
                }
            }
        }

        return 0;
    }
};

// Example usage
int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {1, 1, 0},
        {0, 0, 0}};

    cout << "Maximum Safeness Factor for grid1: " << sol.maximumSafenessFactor(grid1) << endl;

    vector<vector<int>> grid2 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};

    cout << "Maximum Safeness Factor for grid2: " << sol.maximumSafenessFactor(grid2) << endl;

    return 0;
}
