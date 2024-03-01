#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Print adjacency list

// Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph.
// 0-based indexing is followed everywhere.

// Example 1:

// Input:
// V = 5, E = 7
// edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}

// Output:
// {{1,4},
//  {0,2,3,4},
//  {1,3},
//  {1,2,4},
//  {0,1,3}}
// Explanation:
// Node 0 is connected to 1 and 4.
// Node 1 is connected to 0,2,3 and 4.
// Node 2 is connected to 1 and 3.
// Node 3 is connected to 1,2 and 4.
// Node 4 is connected to 0,1 and 3.
// Example 2:

// Input:
// V = 4, E = 3
// edges = {(0,3),(0,2),(2,1)}

// Output:
// {{2,3}
//  {2},
//  {0,1}
//  {0}}
// Explanation:
// Node 0 is connected to 2 and 3.
// Node 1 is only connected to 2.
// Node 2 is connected to 0 and 1.
// Node 3 is only connected to 0.

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
    {
        vector<vector<int>> ans(V);

        for (auto i : edges)
        {
            ans[i.first].push_back(i.second);
            ans[i.second].push_back(i.first);
        }

        return ans;
    }
};

int main()
{
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

    Solution solution;
    vector<vector<int>> adjacencyList = solution.printGraph(V, edges);

    // Print the adjacency list
    for (int i = 0; i < V; ++i)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adjacencyList[i].size(); ++j)
        {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
