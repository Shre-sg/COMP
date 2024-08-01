// Question: Servers
// Problem Statement:
// A company has
// 𝑁
// N servers, labeled from 1 to
// 𝑁
// N. Initially, all servers have no workload.

// The company receives
// 𝑀
// M API requests that need to be handled by these servers. The goal is to distribute the requests evenly among the servers to keep the workload balanced. The workload is balanced when the busiest server has the least possible load.

// Key Requirements:

// Balanced Workload: Distribute the requests such that the difference in the number of requests handled by any two servers is minimized.
// Tie-breaking: If multiple servers have the same workload, assign the request to the server with the smaller label (ID).
// Objective:
// Determine which server will handle each of the
// 𝑀
// M requests and return the sequence of server IDs handling these requests.

// Function Description:
// Implement the function solve() which takes two parameters:

// N: An integer representing the number of servers.
// M: An integer representing the number of requests.
// The function should return a list of integers where each integer represents the server number that will handle the corresponding request in the order they are received.

// Input Format:
// The first line contains an integer
// 𝑁
// N, the number of servers.
// The second line contains an integer
// 𝑀
// M, the number of requests.
// Output Format:
// Return a list of integers representing the server IDs handling each request.
// Example:
// Input:

// Copy code
// 3
// 7
// Output:
// [1, 2, 3, 1, 2, 3, 1]

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solve(int N, int M)
{
    // Define a min-heap priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Initialize the heap with each server having a load of 0
    for (int i = 1; i <= N; ++i)
    {
        minHeap.push(make_pair(0, i));
    }

    vector<int> results;

    // Process each request
    for (int i = 0; i < M; ++i)
    {
        // Get the server with the minimum load
        pair<int, int> server = minHeap.top();
        minHeap.pop();

        // Add the server ID to the results
        results.push_back(server.second);

        // Increase the server's load
        server.first += 1;

        // Push the updated server back into the heap
        minHeap.push(server);
    }

    return results;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> result = solve(N, M);

    for (int server : result)
    {
        cout << server << " ";
    }
    cout << endl;

    return 0;
}
