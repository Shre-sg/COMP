#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// striver algo
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.

    //  Vertex 0: <<{1, 2}, {2, 4}, {4, 3}>>
    //  Vertex 1: <<{2, 1}, {3, 7}>>
    //  Vertex 2: <<{4, 3}, {3, 2}>>
    //  Vertex 3: <<{4, 1}>>
    //  Vertex 4: <<>>

    // For example, for vertex 0, the pairs {1, 2}, {2, 4}, and {4, 3}
    // represent the edges (0, 1) with weight 2, (0, 2) with weight 4, and (0, 4) with weight 3,

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here   //type ele          //type datastr         //compaision
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9); // V is nof nodes in the graph
        pq.push({0, S});
        dist[S] = 0;

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjdis = it[1];
                int adjnode = it[0];
                if (dis + adjdis < dist[adjnode])
                {
                    dist[adjnode] = dis + adjdis;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = 0;
            }
        }
        return dist;
    }
};

int main()
{
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    // Adjacency list representation of the graph
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    Solution obj;
    vector<int> shortest_distances = obj.dijkstra(V, adj, S);

    // Output shortest distances from the source vertex
    for (int i = 0; i < V; i++)
    {
        cout << "Shortest distance from vertex " << S << " to vertex " << i << " is: " << shortest_distances[i] << endl;
    }

    return 0;
}
