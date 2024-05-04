// 1319. Number of Operations to Make Network Connected

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a
// network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any
// computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two
// directly connected computers, and place them between any pair of disconnected computers to make
// them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers
// connected. If it is not possible, return -1.

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void dfs(vector<int> adj[], vector<bool> &visited, int src)
    {
        visited[src] = true;
        for (int i : adj[src])
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &arr)
    {

        int len = arr.size(); // number of edges {{a,b},{b,c}....}
        if (len < n - 1)      // if number of edges is less than min spanning tree we cant connect all ie -1
            return -1;

        vector<int> adj[n];
        for (auto v : arr)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                dfs(adj, visited, i); // DFS to find out how many componets are there like how many graphs
                ans++;
            }
        return ans - 1;
    }
};

int main()
{
    // Example usage
    int n = 5; // Number of nodes
    vector<vector<int>> arr = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 4}};

    Solution sol;
    int minCables = sol.makeConnected(n, arr);

    cout << "Minimum cables required to make the network connected: " << minCables << endl;

    return 0;
}

// see gfg video to understand