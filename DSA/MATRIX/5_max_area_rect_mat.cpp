#include <iostream>
#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

// iven a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

// Example 1:

// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.
// Your Task: 
// Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

// Expected Time Complexity : O(n*m)
// Expected Auixiliary Space : O(m)

// Constraints:
// 1<=n,m<=1000
// 0<=M[][]<=1


class Solution{
  public:
/// this FUN is from max area rect in histrogram
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      
      stack < int > st;
      int leftsmall[n], rightsmall[n];   //string smallest left ,  smallest ele right boundary
      
      for (int i = 0; i < n; i++) {
        
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();   //pops when the stack top hight is more than current tower
        }
        
        if (st.empty())    ///when stack is empty happens when the bound s at the end 
          leftsmall[i] = 0;
        
        else
          leftsmall[i] = st.top() + 1;
        
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
    }
};


int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    int M[MAX][MAX];
    cout << "Enter the matrix (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }

    Solution obj;
    int result = obj.maxArea(M, n, m);

    cout << "The maximum area of the rectangle in the binary matrix is: " << result << endl;

    return 0;
}


