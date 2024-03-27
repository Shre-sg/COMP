#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int vis[N + 1][N + 1]; // Declare a 2D array

        // Initialize the array with zeros
        for (int i = 0; i < N + 1; ++i)
        {
            for (int j = 0; j < N + 1; ++j)
            {
                vis[i][j] = 0;
            }
        }

        // Define the possible moves of the knight
        int dx[8] = {2, 1, 2, -1, -2, -2, -1, 1};
        int dy[8] = {-1, 2, 1, 2, 1, -1, -2, -2};

        // Mark the initial position of the knight as visited
        vis[KnightPos[0]][KnightPos[1]] = 1;
        queue<pair<pair<int, int>, int>> q; // {{x, y}, distance}
        q.push({{KnightPos[0], KnightPos[1]}, 0});

        // Perform BFS
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int k = q.front().second;
            q.pop();
            if (x == TargetPos[0] && y == TargetPos[1])
            {
                return k;
            }

            // Explore possible moves of the knight
            for (int i = 0; i < 8; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                // Check if the next position is valid and not visited
                if (nx > 0 && nx <= N && ny > 0 && ny <= N && vis[nx][ny] == 0)
                {
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, k + 1});
                }
            }
        }

        // If the target position cannot be reached
        return -1;
    }
};

int main()
{
    // Example usage
    vector<int> KnightPos = {1, 1};
    vector<int> TargetPos = {8, 8};
    int N = 8;

    Solution solution;
    int steps = solution.minStepToReachTarget(KnightPos, TargetPos, N);

    cout << "Minimum steps required: " << steps << endl;

    return 0;
}
