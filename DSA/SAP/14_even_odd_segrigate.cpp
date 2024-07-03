#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Segregate Even and Odd numbers
// Last Updated : 27 Feb, 2024
// Given an array A[], write a function that segregates even and odd numbers. The functions should put all even numbers first, and then odd numbers.

//  Example:

// Input  = {12, 34, 45, 9, 8, 90, 3}
// Output = {12, 34, 8, 90, 45, 9, 3}
// In the output, the order of numbers can be changed, i.e., in the above example, 34 can come before 12 and 3 can come before 9.

// Function to segregate even and odd numbers in an array
void segregateEvenOdd(vector<int> &arr)
{
    // Initialize left and right indexes
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        // Increment left index while we see even number at left
        while (arr[left] % 2 == 0 && left < right)
            left++;

        // Decrement right index while we see odd number at right
        while (arr[right] % 2 == 1 && left < right)
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
    vector<int> arr = {12, 34, 45, 9, 8, 90, 3};

    cout << "Original array: ";
    printArray(arr);

    segregateEvenOdd(arr);

    cout << "Array after segregation: ";
    printArray(arr);

    return 0;
}
