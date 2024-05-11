#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 997. Find the Town Judge

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is
// secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2
// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3
// Example 3:

// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1

// Constraints:

// 1 <= n <= 1000
// 0 <= trust.length <= 104
// trust[i].length == 2
// All the pairs of trust are unique.
// ai != bi
// 1 <= ai, bi <= n
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (n == 1)
            return 1;

        unordered_map<int, int> indegree, outdegree;

        for (auto i : trust)
        {
            int trusts = i[0];
            int trusted = i[1];

            indegree[trusted]++;
            outdegree[trusts]++;
        }

        for (auto i : indegree)
        {
            int node = i.first;
            int in = i.second;
            if (in == n - 1 && outdegree[node] == 0)
                return node;
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};

    int judge = solution.findJudge(n, trust);
    if (judge != -1)
    {
        cout << "The town judge is person " << judge << endl;
    }
    else
    {
        cout << "There is no town judge in this town." << endl;
    }

    return 0;
}
