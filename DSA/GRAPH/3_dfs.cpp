
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.4
    void DFS(int node, vector<int> &ans, vector<int> &visited, vector<int> adj[])
    {
        visited[node] = 1;
        ans.push_back(node);
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                DFS(i, ans, visited, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> visited(V, false);
        DFS(0, ans, visited, adj);
        return ans;
    }
};

int main()
{
    int V = 5;          // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);

    Solution solution;                                      // Create an instance of the Solution class
    vector<int> dfsTraversal = solution.dfsOfGraph(V, adj); // Perform DFS traversal

    // Printing DFS traversal result
    for (int i = 0; i < dfsTraversal.size(); ++i)
    {
        cout << dfsTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}
