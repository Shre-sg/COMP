#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        //  MAIN PART OF THE CODE
        for (int deva = 0; deva < n; deva++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[deva][j] + matrix[i][deva]);
                }
            }
        }

        // ACCORDING TO THE QUESTION
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main()
{
    // Example usage
    vector<vector<int>> graph = {
        {0, 5, -1, 10},
        {-1, 0, 3, -1},
        {-1, -1, 0, 1},
        {-1, -1, -1, 0}};

    Solution solution;
    solution.shortest_distance(graph);

    // Output the modified graph
    for (const auto &row : graph)
    {
        for (int distance : row)
        {
            cout << distance << "\t";
        }
        cout << endl;
    }

    return 0;
}
