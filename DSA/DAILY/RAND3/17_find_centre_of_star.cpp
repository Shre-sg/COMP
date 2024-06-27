#include <iostream>
#include <vector>
#include <map>
using namespace std;


// 1791. Find Center of Star Graph

// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 

// Example 1:


// Input: edges = [[1,2],[2,3],[4,2]]
// Output: 2
// Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
// Example 2:

// Input: edges = [[1,2],[5,1],[1,3],[1,4]]
// Output: 1
 

// Constraints:

// 3 <= n <= 105
// edges.length == n - 1
// edges[i].length == 2
// 1 <= ui, vi <= n
// ui != vi
// The given edges represent a valid star graph.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mpp;
        for (int i = 0; i < edges.size(); i++) {
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;
        }
        int nodes = 0;
        for (auto it : mpp) {
            nodes++;
        }
        for (auto it : mpp) {
            if (it.second == nodes - 1)
                return it.first;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    cout << "The center of the star graph is: " << sol.findCenter(edges1) << endl;
    
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {2, 4}, {2, 5}};
    cout << "The center of the star graph is: " << sol.findCenter(edges2) << endl;

    return 0;
}
