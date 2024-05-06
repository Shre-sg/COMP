#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological
// Sorting of that Graph.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.
// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2

class Solution
{
public:
    void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[])
    {
        vis[start] = true;

        for (int nbr : adj[start])
        {
            if (!vis[nbr])
            {
                dfs(nbr, vis, s, adj);
            }
        }

        s.push(start);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, s, adj);
            }
        }

        vector<int> res;
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};

int main()
{
    int V = 6;
    vector<int> adj[V];

    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    vector<int> result = sol.topoSort(V, adj);

    // Print the sorted order
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
