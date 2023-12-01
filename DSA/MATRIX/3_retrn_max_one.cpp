#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Given a boolean 2D array of n x m dimensions where each row is sorted. 
// Find the 0-based index of the first row that has the maximum number of 1's.

// Example 1:
// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).

// Example 2:
// Input: 
// N = 2, M = 2
// Arr[][] = {{0, 0}, {1, 1}}
// Output: 1
// Explanation: Row 1 contains 2 1's (0-based
// indexing).



class Solution {
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
        int c;
        int mc = 0;
        int r = -1;
        for (int i = 0; i < n; i++) {
            c = 0;
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    c++;
                }
            }
            if (c > mc) {
                mc = c;
                r = i;
            }
        }
        return r;
    }
};

int main() {
    vector<vector<int>> arr = {{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    int n = 4, m = 4;
    Solution s;
    cout << "Row with maximum 1s: " << s.rowWithMax1s(arr, n, m) << endl;
    return 0;
}
