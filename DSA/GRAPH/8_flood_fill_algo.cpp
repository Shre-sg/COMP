#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 733. Flood Fill

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel
// value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the
// image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected
// 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels
// connected 4-directionally to those pixels (also with the same color), and so on. Replace the color
// of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored 0, so no changes are made to the image.

// Constraints:

// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], color < 216
// 0 <= sr < m
// 0 <= sc < n

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int startColor = image[sr][sc];

        if (startColor == color)
            return image;

        image[sr][sc] = color;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto d : dir)
            {
                int r = curr.first + d[0];
                int c = curr.second + d[1];

                if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != startColor)
                    continue;

                image[r][c] = color;
                q.push({r, c});
            }
        }

        return image;
    }
};

void printImage(const vector<vector<int>> &image)
{
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution solution;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    cout << "Original Image:" << endl;
    printImage(image);

    vector<vector<int>> newImage = solution.floodFill(image, sr, sc, newColor);

    cout << "\nImage after flood fill:" << endl;
    printImage(newImage);

    return 0;
}
