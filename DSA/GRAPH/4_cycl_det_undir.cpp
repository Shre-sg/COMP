#include <vector>
#include <iostream>
using namespace std;

// Detect cycle in an undirected graph

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges,
// check whether it contains any cycle or not. Graph is in the form of adjacency list where
// adj[i] contains all the nodes ith node is having edge with.

// Example 1:

// Input:
// V = 5, E = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
// Output: 1
// Explanation:

// 1->2->3->4->1 is a cycle.
// Example 2:

// Input:
// V = 4, E = 2
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation:

// No cycle in the graph.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

// NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

class Solution
{
public:
    // DFS function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], vector<bool> &vis, int source, int parent)
    {
        vis[source] = true;
        for (auto u : adj[source])
        {
            if (vis[u] == false)
            {
                // Recursive call to dfs with the adjacent vertex
                // If dfs returns true, a cycle is detected, return true
                if (dfs(adj, vis, u, source))
                {
                    return true;
                }
            }
            // If the adjacent vertex is already visited and not the parent of the current node,
            // it means there's a back edge indicating a cycle
            else if (u != parent)
            {
                return true;
            }
        }

        // If no cycle is detected in this connected component, return false
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Initialize a boolean array to keep track of visited vertices
        vector<bool> vis(V, false);

        // Iterate through all vertices
        for (int i = 0; i < V; i++)
        {
            // If the current vertex is not visited, start dfs from it
            if (vis[i] == false)
            {
                // If dfs returns true, a cycle is detected, return true
                if (dfs(adj, vis, i, -1))
                {
                    return true;
                }
            }
        }

        // If no cycle is detected in the entire graph, return false
        return false;
    }
};

int main()
{
    int V = 4;          // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution solution;                      // Create an instance of the Solution class
    bool cyclic = solution.isCycle(V, adj); // Check if the graph contains a cycle

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

// using BFS
//  class Solution {

//   public:
//     bool bfs(int src,vector<int> adj[],int visited[],int parent_track[])
//     {
//         queue<int> q;
//         q.push(src);
//         visited[src] = 1;

//         while(!q.empty())
//         {
//             int p = q.front();
//             q.pop();

//             // cout<<p<<endl;

//             for(int child:adj[p])
//             {
//                 if(visited[child] && child != parent_track[p])
//                 {
//                     return true;
//                 }
//                 if(!visited[child])
//                 {
//                     q.push(child);
//                     visited[child] = 1;
//                     parent_track[child] = p;
//                 }
//             }
//         }
//         return false;
//     }
//     bool isCycle(int V, vector<int> adj[]) {

//         int parent_track[V] = {-1};
//         int visited[V] = {0};
//         for(int i=0;i<V;i++)
//         {
//             if(!visited[i])
//             {
//                 if(bfs(i,adj,visited,parent_track)) return true;
//             }
//         }

//         return false;
//     }
// };