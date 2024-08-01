#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// To solve this problem, you need to simulate the sequence of operations on the list of transaction values. Each operation involves sorting a prefix of the list in either non-descending or non-ascending order. Here's how you can approach this:

// Steps to Solve the Problem
// Read Input: Start by reading the list of transaction values and the sequence of operations.
// Apply Operations: For each operation, modify the list as specified:
// For a sorting operation in non-descending order, sort the first r_i records in ascending order.
// For a sorting operation in non-ascending order, sort the first r_i records in descending order.
// Output the Final List: After applying all operations, output the final state of the list.

// Explanation
// Function Definition: process_transactions takes a list of transactions and a list of operations.
// Loop Through Operations: For each operation, determine the type of sorting (asc for non-descending and desc for non-ascending) and the length of the prefix (r_i).
// Adjust Prefix Length: Ensure that the prefix length does not exceed the list length.
// Apply Sorting:
// For non-descending, use sorted() without additional arguments.
// For non-ascending, use sorted() with reverse=True.
// Output Final List: After all operations, the final list is returned and printed.
// Example
// Given the initial list [5, 3, 8, 6, 2] and operations ('asc', 3), ('desc', 4), ('asc', 5), the solution will sort the first 3 elements in ascending order, then the first 4 elements in descending order, and finally the first 5 elements in ascending order, resulting in [2, 3, 5, 6, 8].

// This approach ensures that each operation is applied sequentially to the modified list, and the final result accurately reflects the cumulative effect of all operations.

vector<int> f(int n, int m, vector<int> a, vector<pair<int, string>> oper)
{
    // Process each operation
    for (const auto &op : oper)
    {
        int r_i = op.first;
        string sort_type = op.second;

        if (r_i > n)
            r_i = n; // Adjust r_i to be within bounds

        if (sort_type == "asc")
        {
            sort(a.begin(), a.begin() + r_i); // Sort first r_i elements in ascending order
        }
        else if (sort_type == "desc")
        {
            sort(a.begin(), a.begin() + r_i, greater<int>()); // Sort first r_i elements in descending order
        }
    }

    return a;
}

int main()
{
    int op, n;
    cin >> op; // Number of operations
    cin >> n;  // Number of transaction values

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read transaction values
    }

    vector<pair<int, string>> operations(op);
    for (int i = 0; i < op; i++)
    {
        int r_i;
        string type;
        cin >> r_i >> type; // Read each operation: prefix length and sort type
        operations[i] = make_pair(r_i, type);
    }

    vector<int> res = f(n, op, a, operations);

    // Output the final list
    for (const int &value : res)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
