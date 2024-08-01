#include <iostream>
#include <vector>

using namespace std;

vector<int> generateArray(int n)
{
    // Initialize a vector with n+1 elements, all set to 0
    vector<int> ans(n + 1, 0);

    // Populate the vector based on the given rules
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            // For even indices, set the value to ans[i / 2]
            ans[i] = ans[i / 2];
        }
        else
        {
            // For odd indices, set the value to ans[i / 2] + 1
            ans[i] = ans[i / 2] + 1;
        }
    }

    // Return the populated vector
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value for n: ";
    cin >> n;

    vector<int> result = generateArray(n);

    // Print the resulting vector
    cout << "Resulting array: ";
    for (int i = 0; i <= n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
