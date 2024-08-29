#include <bits/stdc++.h>
using namespace std;

// Function to find number of unique BST using memoization
int numberOfBSTUtil(int n, vector<int> &memo)
{
    // Base case
    if (n <= 1)
    {
        return 1;
    }

    // If the result is already computed, return it
    if (memo[n] != -1)
    {
        return memo[n];
    }

    // Calculate the number of unique BSTs recursively
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += numberOfBSTUtil(i - 1, memo) * numberOfBSTUtil(n - i, memo);
    }

    // Store the result in the memoization table
    memo[n] = count;

    return count;
}

int numberOfBST(int n)
{
    // Initialize a memoization table with -1 (indicating uncomputed values)
    vector<int> memo(n + 1, -1);

    // Call the utility function
    return numberOfBSTUtil(n, memo);
}

// Driver Code
int main()
{
    int N = 3;

    // Function call
    cout << "Number of structurally Unique BST with " << N
         << " keys are: " << numberOfBST(N) << "\n";

    return 0;
}
