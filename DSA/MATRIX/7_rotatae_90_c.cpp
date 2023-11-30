#include<bits/stdc++.h>
using namespace std;


//ALGO : Optmaised
// Algorithm / Intuition
// Intuition: By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

// Approach:
// Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
// Step 2: Reverse each row of the matrix.


void rotate(vector < vector < int >> & matrix) {
    
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    rotate(arr);
    
    cout << "Rotated Image" << endl;
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
    }
    
    cout << "n";
    
    }

}


// //buteforce 
//Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
//Space Complexity: O(N*N) to copy it into some other matrix.

// vector < vector < int >> rotate(vector < vector < int >> & matrix) {
//     int n = matrix.size();
//     vector < vector < int >> rotated(n, vector < int > (n, 0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             rotated[j][n - i - 1] = matrix[i][j];  ///this explains the algo add ele ceom input mat to ans mat 
//         }
//     }
//     return rotated;
// }

// int main() {
//     vector < vector < int >> arr;
    
//     arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector < vector < int >> rotated = rotate(arr);
    
//     cout << "Rotated Image" << endl;
//     for (int i = 0; i < rotated.size(); i++) {
//         for (int j = 0; j < rotated[0].size(); j++) {
//             cout << rotated[i][j] << " ";
//         }
//      cout << "n";
//     }

// }