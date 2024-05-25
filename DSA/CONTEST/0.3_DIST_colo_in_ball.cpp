#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 3160. Find the Number of Distinct Colors Among the Balls

// You are given an integer limit and a 2D array queries of size n x 2.
// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

// Note that when answering a query, lack of a color will not be considered as a color.

// Example 1:

// Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

// Output: [1,2,2,3]

// Explanation:

// After query 0, ball 1 has color 4.
// After query 1, ball 1 has color 4, and ball 2 has color 5.
// After query 2, ball 1 has color 3, and ball 2 has color 5.
// After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
// Example 2:

// Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

// Output: [1,2,2,3,4]

// Explanation:

// After query 0, ball 0 has color 1.
// After query 1, ball 0 has color 1, and ball 1 has color 2.
// After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
// After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
// After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> mp1, mp2;
        vector<int> ans;
        for (auto &it : queries)
        {
            int u = it[0];
            int v = it[1];
            if (mp1.find(u) != mp1.end())
            {
                int col = mp1[u];
                mp2[col]--;
                if (mp2[col] == 0)
                    mp2.erase(col);
            }
            mp1[u] = v;
            mp2[v]++;
            ans.push_back(mp2.size());
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int limit = 5;                                                          // Example limit
    vector<vector<int>> queries = {{1, 1}, {2, 2}, {3, 3}, {1, 2}, {2, 3}}; // Example queries
    vector<int> result = sol.queryResults(limit, queries);

    // Print the result
    cout << "Query results:" << endl;
    for (int res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
