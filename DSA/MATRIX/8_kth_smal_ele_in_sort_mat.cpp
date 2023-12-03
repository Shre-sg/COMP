#include<bits/stdc++.h>
using namespace std;
#define MAX 100


//https://youtu.be/dpsp1hP6P-U?si=RyFL7XQBdju29yTO

// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
 

// Example 2:
// Input:
// N = 4
// mat[][] =     {{10, 20, 30, 40}
//                    {15, 25, 35, 45}
//                    {24, 29, 37, 48}
//                    {32, 33, 39, 50}}
// K = 7
// Output: 30
// Explanation: 30 is the 7th smallest element.

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // EXTRA SPACE O(K)
//   priority_queue<int> pq;
//   for(int i = 0; i<n; i++){
//       for(int j = 0; j<n; j++){
//           pq.push(mat[i][j]);
//           if(pq.size() > k){
//               pq.pop();
//           }
//       }
//   }
//   return pq.top();


    // IN-PLACE OPTIMAL APPROACH+binary seqarch approach
    int low = mat[0][0];
    int high = mat[n-1][n-1];
    
    while(low < high){
        
        int count = 0;
        int mid=(high + low)/2;  
        
        //each row i am cou8nting the ele gretaer than mid
        for(int i = 0; i<n; i++){
            count += upper_bound(mat[i], mat[i]+n, mid) - mat[i];
        }                        //row      //row ele      //0
        
        
        if(count < k){
            low = mid+1;   //if count value is low look in the lef6t side
        }
        else{
            high = mid;  // else look in left 
        }
    }
    return low;
}   

int main()
{
    // sample input
    int n = 4;
    int mat[MAX][MAX] = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };
    int k = 3;
    
    // function call
    int ans = kthSmallest(mat, n, k);
    
    // output
    printf("The %dth smallest element in the matrix is %d\n", k, ans);
    
    return 0;
}
