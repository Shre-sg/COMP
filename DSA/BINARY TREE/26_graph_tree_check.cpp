#include <iostream>
#include <list>
using namespace std;

//Check if a given graph is tree or not

//Write a function that returns true if a given undirected graph is a tree and false otherwise. 
//For example, the following graph is a tree.
 


// Approach 1:
// An undirected graph is a tree if it has the following properties. 
// There is no cycle. 
// The graph is connected.

// For an undirected graph, we can either use BFS or DFS to detect the above two properties.

// How to detect cycles in an undirected graph? 
// We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that
// u is already visited and u is not the parent of v, then there is a cycle in the graph. If we don’t
// find such an adjacent for any vertex, we say that there is no cycle (See Detect cycle in an
// undirected graph for more details).

// How to check for connectivity? 
// Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices
// are reachable or not. If all vertices are reachable, then the graph is connected, otherwise not.


// Implementation: 
///https://youtu.be/PBxwRbmZZ2o?si=mvhVtU_2wzg4lgqk
class Graph {
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isTree();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent) {
    
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, v))
                return true;
        } 
        else if (i != parent)
            return true;
    }

    return false;
}

bool Graph::isTree() {
    bool* visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    if (isCyclicUtil(0, visited, -1))
        return false;

    for (int u = 0; u < V; u++)
        if (!visited[u])
            return false;

    return true;
}

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    return 0;
}
