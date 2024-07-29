#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for max and abs
#include <climits>   // for INT_MAX

using namespace std;

// 1631. Path With Minimum Effort

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Example 1:

// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:

// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:

// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Min-heap priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // Directions for moving up, down, left, right
        vector<int> nnrow{-1, 1, 0, 0};
        vector<int> nncol{0, 0, 1, -1};

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int effort = node.first;
            int row = node.second.first;
            int col = node.second.second;

            // If we reached the bottom-right cell
            if (row == n - 1 && col == m - 1)
            {
                return effort;
            }

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + nnrow[i];
                int ncol = col + nncol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int diff = abs(heights[row][col] - heights[nrow][ncol]);
                    int max_effort = max(effort, diff);

                    if (max_effort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = max_effort;
                        pq.push({max_effort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    Solution sol;
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl;

    return 0;
}
