// 787. Cheapest Flights Within K Stops
// Solved
// Medium
// Topics
// Companies
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
// Example 2:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
// Example 3:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

// Constraints:

// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Use a priority queue to keep track of the minimum price
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // Push the source node with 0 stops and 0 price
        pq.push({0, {src, 0}});

        // Create an adjacency list for the graph
        vector<pair<int, int>> adj[n];
        for (auto &flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].push_back({v, price});
        }

        // Distance array to keep track of the minimum price to reach each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!pq.empty())
        {
            // Extract the current element
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int price = pq.top().second.second;
            pq.pop();

            // If the number of stops exceeds k, skip this node
            if (stops > k)
                continue;

            // Traverse all the neighbors of the current node
            for (auto &it : adj[node])
            {
                int neighNode = it.first;
                int neighPrice = it.second;

                // If the total price to reach the neighbor node is less than the recorded price
                if (price + neighPrice < dist[neighNode])
                {
                    // Update the distance to the neighbor node
                    dist[neighNode] = price + neighPrice;
                    // Push the neighbor node into the priority queue with incremented stops
                    pq.push({stops + 1, {neighNode, price + neighPrice}});
                }
            }
        }

        // If we can't reach the destination node, return -1
        if (dist[dst] == INT_MAX)
            return -1;
        // Otherwise, return the minimum price to reach the destination node
        return dist[dst];
    }
};

// Main function to test the solution
int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}};
    int src = 0, dst = 3, k = 1;

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "The cheapest price is: " << result << endl;

    return 0;
}
