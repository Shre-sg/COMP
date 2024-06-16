// 2685. Count the Number of Complete Components
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

// Example 1:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int curr, vector<bool>& visited, int &node, int &edge_c) {
        visited[curr] = true;
        node += 1;
        edge_c += graph[curr].size();
        for (int nex : graph[curr]) {
            if (!visited[nex]) {
                dfs(graph, nex, visited, node, edge_c);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        // Build adjacency list representation of the graph
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int res = 0;
        vector<bool> visited(n);
        
        // Iterate through each node
        for (int i = 0; i < n; i++) {
            int node = 0, edge_c = 0;
            if (!visited[i]) {
                // Perform DFS to count nodes and edges in this component
                dfs(graph, i, visited, node, edge_c);
                
                // Check if this component is a complete component
                //after fist dfs return node = 3 and edge = 6
                if (node * (node - 1) == edge_c) {
                    res += 1;
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
    
    int count = sol.countCompleteComponents(n, edges);
    
    cout << "Number of complete components: " << count << endl;
    
    return 0;
}
