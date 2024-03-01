#include <iostream>
#include <vector>
using namespace std;

// Detect cycle in a directed graph

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it
// contains any cycle or not.

// Exa
// Input:

// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:

// Input:

// Output: 0
// Explanation: no cycle in the graph

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
// In the adjacency list adj, element adj[i][j] represents an edge from i to j.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

class Solution
{
public:
    bool dfs(int s, int V, vector<int> adj[], vector<bool> &visited, vector<bool> &pathvisited)
    {
        visited[s] = true;
        pathvisited[s] = true; // notes if pathis same or not watvh striver

        for (int i : adj[s])
        {
            if (!visited[i])
            {
                if (dfs(i, V, adj, visited, pathvisited) == true) // cycle was alread detected retunr true
                {
                    return true;
                }
            }
            else if (pathvisited[i]) /// this is where the fist cycle was detected
            {
                return true; // when path is visted and node is also visted it is cycle ie collision
            }
        }

        // if no cycle is found retunr flase
        pathvisited[s] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> pathvisited(V, false);

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (dfs(i, V, adj, visited, pathvisited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int V = 4;          // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    Solution solution;                       // Create an instance of the Solution class
    bool cyclic = solution.isCyclic(V, adj); // Check if the graph contains a cycle

    if (cyclic)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
