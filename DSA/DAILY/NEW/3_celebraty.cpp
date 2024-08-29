// Given a square matrix M[][] of size N X N, such that M[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return -1.

// Note: Follow 0 based indexing and M[i][i] will always be 0.

// Examples:

// Input: MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
// Output: id = 2
// Explanation: The person with ID 2 does not know anyone but everyone knows him

// Input: MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} }
// Output: No celebrity
// Explanation: There is no celebrity.

// C++ program to find celebrity
#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &matrix)
{
    return matrix[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int>> &matrix)
{
    // the graph needs not be constructed
    // as the edges can be found by
    // using knows function

    // degree array;
    int indegree[n] = {0}, outdegree[n] = {0};

    // query for all edges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = knows(i, j, matrix);

            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;

    return -1;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int>> matrix = {{0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0}};
    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}

/// stACK
//
// C++ program to find celebrity using
// stack data structure
#include <bits/stdc++.h>
using namespace std;

// knows function check if a knows b
bool knows(int a, int b, vector<vector<int>> &matrix)
{
    return matrix[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int>> &matrix)
{

    stack<int> s;
    // Celebrity
    int C;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B, matrix))
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }

    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C) && (knows(C, i, matrix) || !knows(i, C, matrix)))
            return -1;
    }

    return C;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int>> matrix = {{0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0}};

    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}

// BINARY SEARCH
//
//
#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &matrix, int n)
{
    // This function returns the celebrity
    // index 0-based (if any)

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (matrix[j][i] == 1) // j knows i
            j--;
        else // j doesnt know i so i cant be celebrity
            i++;
    }
    // i points to our celebrity candidate
    int candidate = i;

    // Now, all that is left is to check that whether
    // the candidate is actually a celebrity i.e: he is
    // known by everyone but he knows no one
    for (i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (matrix[i][candidate] == 0 || matrix[candidate][i] == 1)
                return -1;
        }
    }
    // if we reach here this means that the candidate
    // is really a celebrity
    return candidate;
}

int main()
{
    int n = 4;
    vector<vector<int>> matrix = {{0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0}};

    int celebIdx = celebrity(matrix, n);

    if (celebIdx == -1)
        cout << ("No Celebrity");
    else
    {
        cout << "Celebrity ID " << celebIdx;
    }
    return 0;
}
