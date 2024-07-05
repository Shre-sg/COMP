#include <iostream>
#include <vector>

using namespace std;

// recusion
void printSubsequences(vector<int> &arr, int index, vector<int> &current)
{
    // Base case: If we have reached the end of the array, print the current subsequence
    if (index == arr.size())
    {
        // Print the current subsequence
        for (int num : current)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element in the subsequence
    current.push_back(arr[index]);
    printSubsequences(arr, index + 1, current); // Recursively explore subsequences with the current element

    // Exclude the current element from the subsequence
    current.pop_back();
    printSubsequences(arr, index + 1, current); // Recursively explore subsequences without the current element
}

int main()
{
    vector<int> arr = {1, 2, 3};

    // Empty vector to store the current subsequence
    vector<int> current;

    cout << "All subsequences of the array: " << endl;
    printSubsequences(arr, 0, current);

    return 0;
}