#include <iostream>
#include <vector>
#include <algorithm> // for max

using namespace std;

// 1395. Count Number of Teams
// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

// You have to form a team of 3 soldiers amongst them under the following rules:

// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] <     rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

// Example 1:

// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
// Example 2:

// Input: rating = [2,1,3]
// Output: 0
// Explanation: We can't form any team given the conditions.
// Example 3:

// Input: rating = [1,2,3,4]
// Output: 4

// Constraints:

// n == rating.length
// 3 <= n <= 1000
// 1 <= rating[i] <= 105
// All the integers in rating are unique.

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int maxi = 0;
        for (const int &i : rating)
        {
            maxi = max(maxi, i);
        }
        vector<vector<int>> adj1(maxi + 1), adj2(maxi + 1);
        for (int i = 0; i < rating.size(); i++)
        {
            for (int j = i + 1; j < rating.size(); j++)
            {
                if (rating[i] > rating[j])
                {
                    adj1[rating[i]].push_back(rating[j]);
                }
                else if (rating[i] < rating[j])
                {
                    adj2[rating[i]].push_back(rating[j]);
                }
            }
        }

        int res = 0;
        for (const int &i : rating)
        {
            for (const int &j : adj1[i])
                res += adj1[j].size();
            for (const int &j : adj2[i])
                res += adj2[j].size();
        }

        return res;
    }
};

int main()
{
    vector<int> rating = {2, 5, 3, 4, 1};
    Solution sol;
    int result = sol.numTeams(rating);
    cout << "Number of teams: " << result << endl;
    return 0;
}

///
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
                        (rating[i] > rating[j] && rating[j] > rating[k]))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

// adj1 = [[], [], [1], [1], [1], [3, 4, 1]]

// adj2 = [[], [], [5, 3, 4], [], [4], []]

// last loop
//  i=2:

// adj1[2] = [1]: adj1[1].size() = 0
// adj2[2] = [5, 3, 4]: adj2[5].size() = 0, adj2[3].size() = 1, adj2[4].size() = 0
// res += 0 + 1 + 0 = 1
// i=5:

// adj1[5] = [3, 4, 1]: adj1[3].size() = 1, adj1[4].size() = 1, adj1[1].size() = 0
// adj2[5] = []
// res += 1 + 1 + 0 = 2
// i=3:

// adj1[3] = [1]: adj1[1].size() = 0
// adj2[3] = [4]: adj2[4].size() = 0
// res += 0 + 0 = 2
// i=4:

// adj1[4] = [1]: adj1[1].size() = 0
// adj2[4] = []
// res += 0 = 2
// i=1:

// adj1[1] = []
// adj2[1] = []
// res += 0 = 2