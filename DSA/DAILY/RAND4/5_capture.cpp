#include <iostream>
#include <vector>

using namespace std;

// 130. Surrounded Regions

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:

// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        { // rows first and last ele
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        for (int i = 1; i < n - 1; i++)
        { // col first and last
            if (board[0][i] == 'O')
                DFS(board, 0, i, m, n);
            if (board[m - 1][i] == 'O')
                DFS(board, m - 1, i, m, n);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void DFS(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != 'O')
            return;
        board[i][j] = '$';
        DFS(board, i + 1, j, m, n);
        DFS(board, i - 1, j, m, n);
        DFS(board, i, j + 1, m, n);
        DFS(board, i, j - 1, m, n);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    cout << "Original board:" << endl;
    for (const auto &row : board)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    Solution().solve(board);

    cout << "Solved board:" << endl;
    for (const auto &row : board)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
