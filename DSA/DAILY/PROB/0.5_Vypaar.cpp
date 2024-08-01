#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(int N, int M, vector<int> req)
{
    // Min-heap to store the servers, based on their current load and ID
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Initially, all servers are free with a load of 0
    for (int i = 1; i <= N; ++i)
    {
        minHeap.push(make_pair(0, i));
    }

    vector<int> results;

    // Assign each task to the server that will be free the earliest
    for (int i = 0; i < M; ++i)
    {
        auto server = minHeap.top(); // Get the server with the minimum load
        minHeap.pop();

        results.push_back(server.second); // Store the server ID assigned to this task

        server.first += req[i]; // Update the server's load with the current task's load

        minHeap.push(server); // Push the updated server back into the heap
    }

    return results;
}

int main()
{
    int N = 3;                         // Number of servers
    int M = 5;                         // Number of tasks
    vector<int> req = {4, 2, 7, 1, 5}; // Load required for each task

    vector<int> result = solve(N, M, req);

    // Output the server assignment for each task
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Task " << i + 1 << " is assigned to server " << result[i] << endl;
    }

    return 0;
}

/// CUSTOM COMPARATOR
auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
{
    // Custom comparator for the priority queue
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
};

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);