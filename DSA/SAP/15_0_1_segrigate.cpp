#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to segregate 0s and 1s in an array
void segregateZeroOne(vector<int> &arr)
{
    // Initialize left and right indexes
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        // Increment left index while we see 0 at left
        while (arr[left] == 0 && left < right)
            left++;

        // Decrement right index while we see 1 at right
        while (arr[right] == 1 && left < right)
            right--;

        if (left < right)
        {
            // Swap arr[left] and arr[right]
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 0, 0, 1, 0, 1};

    cout << "Original array: ";
    printArray(arr);

    segregateZeroOne(arr);

    cout << "Array after segregation: ";
    printArray(arr);

    return 0;
}
