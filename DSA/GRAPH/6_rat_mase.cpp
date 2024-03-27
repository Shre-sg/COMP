#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        dfs(m, ans, "", 0, 0, n);
        return ans;
    }

private:
    void dfs(vector<vector<int>> &m, vector<string> &ans, string path, int i, int j, int n)
    {
        // Check boundaries and obstacles
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0)
            return;

        // Base case: reached the bottom-right corner
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }
        // Store the current cell value and mark it as visited
        int temp = m[i][j];
        m[i][j] = 0;

        // Explore all possible directions
        dfs(m, ans, path + 'D', i + 1, j, n); // Down
        dfs(m, ans, path + 'U', i - 1, j, n); // Up
        dfs(m, ans, path + 'R', i, j + 1, n); // Right
        dfs(m, ans, path + 'L', i, j - 1, n); // Left

        // Restore the original cell value
        m[i][j] = temp;
    }
};

int main()
{
    // Example usage:
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}};
    int n = 3;

    Solution solution;
    vector<string> paths = solution.findPath(matrix, n);

    // Output the found paths
    cout << "Possible paths:" << endl;
    for (const string &path : paths)
    {
        cout << path << endl;
    }

    return 0;
}
