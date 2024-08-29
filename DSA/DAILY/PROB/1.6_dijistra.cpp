#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to convert adjacency matrix to adjacency list
vector<vector<pair<int, int>>> matrixToAdjList(const vector<vector<int>> &matrix)
{
    int V = matrix.size();                     // Number of vertices
    vector<vector<pair<int, int>>> adjList(V); // Adjacency list

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (matrix[i][j] != 0)
            { // There is an edge from i to j
                adjList[i].push_back({j, matrix[i][j]});
            }
        }
    }

    return adjList;
}

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>> &adjList, int src)
{
    int V = adjList.size();        // Number of vertices
    vector<int> dist(V, INT_MAX);  // Distance from source to each vertex
    vector<bool> sptSet(V, false); // Shortest path tree set

    dist[src] = 0; // Distance from source to itself is 0

    // Min-Heap to extract the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, src}); // (distance, vertex)

    while (!minHeap.empty())
    {
        int u = minHeap.top().second; // Get the vertex with the smallest distance
        minHeap.pop();

        if (sptSet[u])
            continue; // Skip if already processed

        sptSet[u] = true;

        // Iterate through all adjacent vertices of u
        for (const auto &neighbor : adjList[u])
        {
            int v = neighbor.first;       // Neighbor vertex
            int weight = neighbor.second; // Weight of edge u-v

            // If the distance to the neighbor can be shortened
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                minHeap.push({dist[v], v}); // Add to heap with updated distance
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }
}

int main()
{
    // Example adjacency matrix for a directed graph
    vector<vector<int>> matrix = {
        {0, 4, 0, 9},
        {0, 0, 8, 0},
        {0, 0, 0, 7},
        {9, 0, 0, 0}};

    // Convert matrix to adjacency list
    vector<vector<pair<int, int>>> adjList = matrixToAdjList(matrix);

    // Perform Dijkstra's algorithm with vertex 0 as the source
    int sourceVertex = 0;
    dijkstra(adjList, sourceVertex);

    return 0;
}
