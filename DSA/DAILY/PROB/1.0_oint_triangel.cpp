#include <bits/stdc++.h>
using namespace std;

// Check whether a given point lies inside a triangle or not
// Last Updated : 18 Sep, 2023
// Given three corner points of a triangle, and one more point P. Write a function to check whether P lies within the triangle or not.

// Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
// Output: Inside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /   P   \      P'
//             /         \
//      A(0,0) ----------- C(20,0)
// Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
// Output: Outside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /       \      P
//             /         \
//      A(0,0) ----------- C(20,0)

//
// If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    float A = area(x1, y1, x2, y2, x3, y3);
    float A1 = area(x, y, x2, y2, x3, y3);
    float A2 = area(x1, y1, x, y, x3, y3);
    float A3 = area(x1, y1, x2, y2, x, y);
    return (A == A1 + A2 + A3);
}

int main()
{
    if (isInside(0, 0, 20, 0, 10, 30, 10, 15))
        cout << "Inside";
    else
        cout << "Not Inside";

    return 0;
}
