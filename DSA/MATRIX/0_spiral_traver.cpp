#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Example 1:

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Explanation:

// Example 2:

// Input:
// r = 3, c = 4  
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output: 
// 1 2 3 4 8 12 11 10 9 5 6 7
// Explanation:
// Applying same technique as shown above, 
// output for the 2nd testcase will be 
// 1 2 3 4 8 12 11 10 9 5 6 7.

// Your Task:
// You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

// Expected Time Complexity: O(r*c)
// Expected Auxiliary Space: O(r*c), for returning the answer only.


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int startRow = 0;
        int endCol = c-1;
        int endRow = r-1;
        int startCol = 0;
        
        int total_element = r*c;
        int count = 0;
        
        while(count < total_element) {
            //Print Start Row
            for(int i=startCol; i<=endCol && count < total_element; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++; // 1   IMOP
            
            //Print End Col
            for(int i =startRow; i<= endRow && count < total_element; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--; // 2    IMPO
            
            //Print End Row
            for(int i= endCol; i>=startCol && count < total_element; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;//2   IMPO 
            
            
            //Print Start Col
            for(int i=endRow; i>=startRow && count < total_element; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++; //1    IMPO
        }
        
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                  {5, 6, 7, 8}, 
                                  {9, 10, 11, 12}, 
                                  {13, 14, 15, 16}};
    int r = 4, c = 4;
    vector<int> ans = Solution().spirallyTraverse(matrix, r, c);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
