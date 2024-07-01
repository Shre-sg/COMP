#include <iostream>
#include <vector>
using namespace std;

// 1550. Three Consecutive Odds

// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

// Example 1:

// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.
// Example 2:

// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.

// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        // Ensure the vector has at least 3 elements
        if (arr.size() < 3)
        {
            return false;
        }

        // Loop through the array up to the third last element
        for (int i = 0; i <= arr.size() - 3; ++i)
        {
            // Check if arr[i], arr[i+1], and arr[i+2] are all odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> test1 = {2, 6, 4, 1};
    vector<int> test2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    vector<int> test3 = {1, 3, 5, 7};

    cout << "Test 1: " << (solution.threeConsecutiveOdds(test1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solution.threeConsecutiveOdds(test2) ? "True" : "False") << endl;
    cout << "Test 3: " << (solution.threeConsecutiveOdds(test3) ? "True" : "False") << endl;

    return 0;
}
