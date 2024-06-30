#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 3200. Maximum Height of a Triangle

// You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.

// All the balls in a particular row should be the same color, and adjacent rows should have different colors.

// Return the maximum height of the triangle that can be achieved.

// Example 1:
// Input: red = 2, blue = 4
// Output: 3
// Explanation:
// The only possible arrangement is shown above.

// Example 2:
// Input: red = 2, blue = 1
// Output: 2
// Explanation:
// The only possible arrangement is shown above.

// Example 3:
// Input: red = 1, blue = 1
// Output: 1

// Example 4:
// Input: red = 10, blue = 1
// Output: 2
// Explanation:
// The only possible arrangement is shown above.

// Constraints:
// 1 <= red, blue <= 100

class Solution
{
public:
    int maxHeightOfTriangle(int red, int blue)
    {
        return max(f(red, blue), f(blue, red));
    }

    int f(int a, int b)
    {
        int h = 0;
        int i = 1;
        bool flag = false;

        while (a > 0 || b > 0)
        {
            if (!flag && a - i >= 0)
            {
                a -= i;
                h++;
                flag = true;
            }
            else if (flag && b - i >= 0)
            {
                b -= i;
                h++;
                flag = false;
            }
            else
            {
                break;
            }
            i++;
        }

        return h;
    }
};

int main()
{
    Solution solution;
    int redSticks = 5;  // Example: Replace with your desired red sticks count
    int blueSticks = 7; // Example: Replace with your desired blue sticks count

    int maxHeight = solution.maxHeightOfTriangle(redSticks, blueSticks);
    std::cout << "Max height of triangle: " << maxHeight << std::endl;

    return 0;
}
