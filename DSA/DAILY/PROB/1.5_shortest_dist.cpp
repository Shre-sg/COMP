#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

// Certainly! The problem you're tackling involves finding the minimum time required to travel from a starting cell

// (0,0) to a target cell

// (x,y) in a grid. Here's a detailed explanation:

// Problem Breakdown
// Grid Representation:

// The grid is a 2D matrix where each cell can either be an open cell (denoted by 0) or a wall (denoted by 1).
// You can move from one cell to its adjacent cells if they are open and not blocked by walls.
// Objective:

// Determine the shortest path from the starting cell

// (0,0) to the target cell

// (x,y) in terms of the number of moves or steps required.
// Each move from one cell to an adjacent cell counts as a unit of time (or distance).
// Constraints:

// The starting cell
// (0,0) and the target cell

// (x,y) are guaranteed to be open cells (not walls).
// Cells that are walls cannot be traversed.
// Approach:

// Breadth-First Search (BFS) is a suitable approach for this problem because it explores all possible moves from the current cell level by level, ensuring that the first time a cell is reached, it is reached by the shortest path.
// BFS is typically implemented using a queue to explore each cell's neighbors.
// Steps to Solve the Problem
// Initialization:

// Use a queue to keep track of cells to be explored, starting with the cell

// (0,0).
// Maintain a distance matrix (or array) to record the minimum distance (or time) required to reach each cell from

// (0,0). Initialize the distance for

// (0,0) to 0 and all other cells to a large value (e.g., infinity).
// BFS Traversal:

// Dequeue the current cell.
// Explore its neighboring cells (up, down, left, right).
// If a neighboring cell is within bounds, is open, and hasn't been visited or can be reached in a shorter time, update its distance and enqueue it for further exploration.
// Termination:

// Once BFS completes, check the distance value for the target cell
// (x,y). If it is still the large value, it means
// (x,y) is unreachable from
// (0,0). Otherwise, the value represents the minimum time required.

const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up

int minTimeToReach(int x, int y, const vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Initialize BFS queue and distance matrix
    queue<pair<int, int>> q;
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        int cur_dist = dist[cur_x][cur_y];

        for (const auto &dir : directions)
        {
            int next_x = cur_x + dir[0];
            int next_y = cur_y + dir[1];

            if (next_x >= 0 && next_x < rows && next_y >= 0 && next_y < cols && grid[next_x][next_y] == 0)
            {
                if (dist[next_x][next_y] > cur_dist + 1)
                {
                    dist[next_x][next_y] = cur_dist + 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }

    return dist[x][y] == INT_MAX ? -1 : dist[x][y];
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}};

    int x = 3, y = 3;
    int result = minTimeToReach(x, y, grid);

    if (result != -1)
    {
        cout << "Minimum time to reach (" << x << ", " << y << ") is " << result << endl;
    }
    else
    {
        cout << "(" << x << ", " << y << ") is unreachable" << endl;
    }

    return 0;
}
