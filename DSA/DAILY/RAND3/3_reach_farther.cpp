#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1642. Furthest Building You Can Reach
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed),

// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

// Example 1:

// Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
// Output: 4
// Explanation: Starting at building 0, you can follow these steps:
// - Go to building 1 without using ladders nor bricks since 4 >= 2.
// - Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
// - Go to building 3 without using ladders nor bricks since 7 >= 6.
// - Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
// It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
// Example 2:

// Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
// Output: 7
// Example 3:

// Input: heights = [14,3,19,3], bricks = 17, ladders = 0
// Output: 3

// Constraints:

// 1 <= heights.length <= 105
// 1 <= heights[i] <= 106
// 0 <= bricks <= 109
// 0 <= ladders <= heights.length

class Solution
{
public:
    int furthestBuilding(vector<int> &h, int b, int l)
    {

        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int> p;

        int i = 0, diff = 0;
        for (i = 0; i < h.size() - 1; i++)
        {
            diff = h[i + 1] - h[i];

            if (diff <= 0)
            {
                continue;
            }

            b -= diff;
            p.push(diff);

            if (b < 0)
            {
                b += p.top();
                p.pop();
                l--;
            }

            if (l < 0)
                break;
        }

        return i;
    }
};

int main()
{
    vector<int> heights;
    int n, bricks, ladders;

    cout << "Enter number of buildings: ";
    cin >> n;
    heights.resize(n);

    cout << "Enter heights of buildings: ";
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << "Enter number of bricks: ";
    cin >> bricks;

    cout << "Enter number of ladders: ";
    cin >> ladders;

    Solution sol;
    int furthest = sol.furthestBuilding(heights, bricks, ladders);

    cout << "Furthest building you can reach: " << furthest << endl;

    return 0;
}
// one more heap approach

// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int i = 0; i < heights.size() - 1; ++i) {
//             int diff = heights[i + 1] - heights[i];

//             if (diff > 0) {
//                 pq.push(diff);

//                 if (pq.size() > ladders) {
//                     int smallest_diff = pq.top();
//                     pq.pop();
//                     bricks -= smallest_diff;

//                     if (bricks < 0) {
//                         return i;
//                     }
//                 }
//             }
//         }
//         return heights.size() - 1;
//     }
// };

// recusion
//  class Solution {
//  private:
//      int solve(int index, vector<int>& heights, int bricks, int ladders){
//          if(index == heights.size()-1) return 0;

//         if(heights[index] >= heights[index+1]){
//             return 1 + solve(index+1, heights, bricks, ladders);
//         }
//         else{
//             int diff = heights[index+1]-heights[index];
//             int byBricks = 0, byLadders = 0;
//             if(bricks >= diff){
//                 byBricks = 1 + solve(index+1, heights, bricks-diff, ladders);
//             }
//             if(ladders > 0){
//                 byLadders = 1 + solve(index+1, heights, bricks, ladders-1);
//             }
//             return max(byBricks, byLadders);
//         }
//     }
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders){
//         return solve(0, heights, bricks, ladders);
//     }
// };

// 2D Dp
//  class Solution {
//  private:
//      int solve(int index, vector<int>& heights, int bricks, int ladders, vector<vector<int>>&dp){
//          if(index == heights.size()-1) return 0;
//          if(dp[bricks][ladders] != -1) return dp[bricks][ladders];

//         if(heights[index] >= heights[index+1]){
//             return dp[bricks][ladders] = 1 + solve(index+1, heights, bricks, ladders, dp);
//         }
//         else{
//             int diff = heights[index+1]-heights[index];
//             int byBricks = 0, byLadders = 0;
//             if(bricks >= diff){
//                 byBricks = 1 + solve(index+1, heights, bricks-diff, ladders, dp);
//             }
//             if(ladders > 0){
//                 byLadders = 1 + solve(index+1, heights, bricks, ladders-1, dp);
//             }
//             return dp[bricks][ladders] = max(byBricks, byLadders);
//         }
//     }
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders){
//         int n = heights.size();
//         vector<vector<int>> dp(bricks+1, vector<int>(ladders + 1, -1));
//         return solve(0, heights, bricks, ladders, dp);
//     }
// };

// 3d DP
// class Solution
// {
// private:
//     int solve(int index, vector<int> &heights, int bricks, int ladders, vector<vector<vector<int>>> &dp)
//     {
//         if (index == heights.size() - 1)
//             return 0;
//         if (dp[index][bricks][ladders] != -1)
//             return dp[index][bricks][ladders];

//         if (heights[index] >= heights[index + 1])
//         {
//             return dp[index][bricks][ladders] = 1 + solve(index + 1, heights, bricks, ladders, dp);
//         }
//         else
//         {
//             int diff = heights[index + 1] - heights[index];
//             int byBricks = 0, byLadders = 0;
//             if (bricks >= diff)
//             {
//                 byBricks = 1 + solve(index + 1, heights, bricks - diff, ladders, dp);
//             }
//             if (ladders > 0)
//             {
//                 byLadders = 1 + solve(index + 1, heights, bricks, ladders - 1, dp);
//             }
//             return dp[index][bricks][ladders] = max(byBricks, byLadders);
//         }
//     }

// public:
//     int furthestBuilding(vector<int> &heights, int bricks, int ladders)
//     {
//         int n = heights.size();
//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
//         return solve(0, heights, bricks, ladders, dp);
//     }
// };