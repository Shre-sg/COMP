#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Explanation
// Spider-Man is at the PhonePe headquarters, which consists of multiple interconnected towers of varying heights. His task is to move from the first tower to the last tower using the least amount of energy possible.

// Movement Options
// Spider-Man has two ways to move between towers:

// Use Spider Silk:

// Cost:
// 𝑥
// x energy points.
// Move: He can move up to
// 𝑘
// k towers to the right, landing on the first tower that is taller than his current tower. If there is no taller tower within the next
// 𝑘
// k towers, he cannot use this method.
// Jump:

// Cost:
// 𝑦
// y energy points.
// Move: He can jump to one of the next two towers to the right.
// Objective
// Find the minimum energy points required for Spider-Man to travel from the first tower (index 0) to the last tower (index
// 𝑛
// −
// 1
// n−1).

// Input Format
// An integer
// 𝑛
// n: the number of towers.
// A list of integers representing the heights of the towers.
// An integer
// 𝑘
// k: the maximum number of towers Spider-Man can consider for the spider silk move.
// An integer
// 𝑥
// x: the energy cost of using the spider silk move.
// An integer
// 𝑦
// y: the energy cost of using the jump move.
// Output
// The minimum energy points required for Spider-Man to reach the last tower.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function to recursively compute minimum energy with memoization
int min_energy_helper(int i, int n, vector<int> &heights, int k, int x, int y, vector<int> &memo)
{
    // Base case: if we've reached the last tower
    if (i >= n - 1)
    {
        return 0;
    }

    // If this subproblem has already been solved, return the stored result
    if (memo[i] != -1)
    {
        return memo[i];
    }

    int silk_min_energy = INT_MAX;
    int one_jump_min_energy = INT_MAX;
    int two_jump_min_energy = INT_MAX;

    // Spider Silk method
    for (int j = 1; j <= k; j++)
    {
        if (i + j < n && heights[i + j] > heights[i])
        {
            silk_min_energy = x + min_energy_helper(i + j, n, heights, k, x, y, memo);
            break; // Only the first taller tower is considered
        }
    }

    // Jump method
    if (i + 1 < n)
    {
        one_jump_min_energy = y + min_energy_helper(i + 1, n, heights, k, x, y, memo);
    }
    if (i + 2 < n)
    {
        two_jump_min_energy = y + min_energy_helper(i + 2, n, heights, k, x, y, memo);
    }

    // Calculate the minimum energy for the current tower
    int min_energy = min(silk_min_energy, min(one_jump_min_energy, two_jump_min_energy));

    // Store the result in memo array before returning
    memo[i] = min_energy;
    return memo[i];
}

// Main function to calculate minimum energy required
int min_energy(int n, vector<int> &heights, int k, int x, int y)
{
    vector<int> memo(n, -1);
    return min_energy_helper(0, n, heights, k, x, y, memo);
}

int main()
{
    int n, k, x, y;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cin >> k >> x >> y;

    cout << min_energy(n, heights, k, x, y) << endl;

    return 0;
}

int main()
{
    int n, k, x, y;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cin >> k >> x >> y;

    cout << min_energy(n, heights, k, x, y) << endl;

    return 0;
}
