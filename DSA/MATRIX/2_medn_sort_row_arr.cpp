#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

//WATCH TUF vid
// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

// Example 1:

// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives 
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

// Example 2:

// Input:
// R = 3, C = 1
// M = [[1], [2], [3]]
// Output: 2
// Explanation: Sorting matrix elements gives 
// us {1,2,3}. Hence, 2 is median.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

// Expected Time Complexity: O(32 * R * log(C))
// Expected Auxiliary Space: O(1)


class Solution {
public:
    int median(vector<vector<int>>& matrix, int R, int C) {
        // Initialize the minimum and maximum values for the binary search range.
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        // Find the minimum and maximum values in the matrix.
        for (int i = 0; i < R; ++i) {
            min_val = min(min_val, matrix[i][0]);       // Minimum value in the first column
            max_val = max(max_val, matrix[i][C - 1]);   // Maximum value in the last column
        }

        // Binary search to find the median.
        while (min_val < max_val) {
            int mid_val = min_val + (max_val - min_val) / 2;
            int count = 0; // Count of elements less than or equal to mid_val

            // Count the number of elements less than or equal to mid_val in each row.
            for (int i = 0; i < R; ++i) {  //itertaor to ele which is max xof mid  -   ///0 index
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid_val) - matrix[i].begin();
            }

            // If count is less than or equal to (R * C) / 2, update the minimum value.
            if (count <= (R * C) / 2) {
                min_val = mid_val + 1;
            } 
            // If count is greater than (R * C) / 2, update the maximum value.
            else {
                max_val = mid_val;
            }
        }

        // At this point, min_val will be the median.
        return min_val;
    }
};


int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int R = matrix.size();    // Number of rows
    int C = matrix[0].size(); // Number of columns

    Solution sol;

    // Call the median function
    int result = sol.median(matrix, R, C);

    // Print the result
    cout << "Median: " << result << endl;

    return 0;
}






// int countEleSmallerEqualToMid(vector<int>& arr,int m,int mid){
//         int low=0, high=m-1;
//         while(low<=high){
//             int mid_=((low+high)>>1);
//             if(arr[mid_]<=mid){
//                 low=mid_+1;
//              else if(arr[mid_]>mid){
//                 high=mid_-1;
//             }
//         }
//         return low;
//     }
    
 
//     int median(vector<vector<int>> &arr, int n, int m){
//         // code here
//         int low=1, high=2000;
//         while(low<=high){
//             int mid=((low+high)>>1);
//             int cnt=0;
//             for(int i=0;i<n;i++){
//                 cnt+=countEleSmallerEqualToMid(arr[i],m,mid);
//                 // cnt+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
//             }
//             if(cnt<=((n*m)>>1)){
//                 low=mid+1;
//             }else{
//                 high=mid-1;
//             }
//         }
//         return low;
//     }







// Naive solution class Solution {
//     int median(int matrix[][], int R, int C) {
//         // code here     
//         int [] med = new int[R*C];
//         int index = 0;
        
//         for(int i = 0; i<R; i++)
//         {
//             for(int j = 0; j< C; j++)
//             {
//                 med[index] = matrix[i][j];
//                 index++;
//             }
//         }
//           Arrays.sort(med);
//         return med[(R*C)/2];
        
//     }
// }

