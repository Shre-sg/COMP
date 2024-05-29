// 1049. Last Stone Weight II
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
// we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
// we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
// we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
// Example 2:

// Input: stones = [31,26,33,21,40]
// Output: 5

// Constraints:

// 1 <= stones.length <= 30
// 1 <= stones[i] <= 100

// algo watch code shark
//  This is similar to the problem "Minimum Subset Difference"
//  i.e. Split the array into two subsets (S1, S2), such that absolute difference between
//  sum(S1) and sum(S2) is minimum.
//  NOTE: sum(S1) = sum of all elements in subset S1

#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int t[31][5051];

    int minDiffSubset(vector<int> &stones, int n, int s1, int sum)
    {
        if (n == 0)
            return abs(sum - 2 * s1);

        if (t[n][s1] != -1)
            return t[n][s1];

        int take = minDiffSubset(stones, n - 1, s1 + stones[n - 1], sum);
        int nottake = minDiffSubset(stones, n - 1, s1, sum);
        return t[n][s1] = min(take, nottake);
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        memset(t, -1, sizeof(t));
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        return minDiffSubset(stones, n, 0, sum);
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    vector<int> stones2 = {31, 26, 33, 21, 40};
    vector<int> stones3 = {1, 2};
    vector<int> stones4 = {3, 7, 8, 2, 4};

    cout << "Minimum possible weight of last stone for stones1: " << solution.lastStoneWeightII(stones1) << endl;
    cout << "Minimum possible weight of last stone for stones2: " << solution.lastStoneWeightII(stones2) << endl;
    cout << "Minimum possible weight of last stone for stones3: " << solution.lastStoneWeightII(stones3) << endl;
    cout << "Minimum possible weight of last stone for stones4: " << solution.lastStoneWeightII(stones4) << endl;

    return 0;
}
