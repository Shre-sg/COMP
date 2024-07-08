#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 221. Maximal Square
// Solved
// Medium
// Topics
// Companies
// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:

// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

class Solution
{
public:
    int findMaxSquare(vector<vector<char>> &matrix, int row, int col, int &maxSideLength, vector<vector<int>> &memo)
    {
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;
        if (memo[row][col] != -1)
            return memo[row][col];

        int right = findMaxSquare(matrix, row, col + 1, maxSideLength, memo);
        int diagonal = findMaxSquare(matrix, row + 1, col + 1, maxSideLength, memo);
        int down = findMaxSquare(matrix, row + 1, col, maxSideLength, memo);

        if (matrix[row][col] == '1')
        {
            int currentSideLength = 1 + min({right, diagonal, down});
            memo[row][col] = currentSideLength;
            maxSideLength = max(maxSideLength, currentSideLength);
            return memo[row][col];
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxSideLength = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        findMaxSquare(matrix, 0, 0, maxSideLength, memo);
        return maxSideLength * maxSideLength;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    int maxSquareArea = solution.maximalSquare(matrix);
    cout << "The area of the largest square is: " << maxSquareArea << endl;
    return 0;
}

// recuriosm
class Solution
{
public:
    int findMaxSquare(vector<vector<char>> &matrix, int row, int col, int &maxSideLength)
    {
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;

        int right = findMaxSquare(matrix, row, col + 1, maxSideLength);
        int diagonal = findMaxSquare(matrix, row + 1, col + 1, maxSideLength);
        int down = findMaxSquare(matrix, row + 1, col, maxSideLength);

        if (matrix[row][col] == '1')
        {
            int currentSideLength = 1 + min({right, diagonal, down});
            maxSideLength = max(maxSideLength, currentSideLength);
            return currentSideLength;
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxSideLength = 0;
        findMaxSquare(matrix, 0, 0, maxSideLength);
        return maxSideLength * maxSideLength;
    }
};