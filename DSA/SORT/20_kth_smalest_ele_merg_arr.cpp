#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Given two arrays arr1 and arr2 of size N and M respectively and an element K. 
//The task is to find the element that would be at the kth position of the final sorted array.
 

// Example 1:

// Input:
// arr1[] = {2, 3, 6, 7, 9}
// arr2[] = {1, 4, 8, 10}
// k = 5
// Output:
// 6
// Explanation:
// The final sorted array would be -
// 1, 2, 3, 4, 6, 7, 8, 9, 10
// The 5th element of this array is 6.
// Example 2:
// Input:
// arr1[] = {100, 112, 256, 349, 770}
// arr2[] = {72, 86, 113, 119, 265, 445, 892}
// k = 7
// Output:
// 256
// Explanation:
// Final sorted array is - 72, 86, 100, 112,
// 113, 119, 256, 265, 349, 445, 770, 892
// 7th element of this array is 256.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.


// Expected Time Complexity: O(Log(N) + Log(M))
// Expected Auxiliary Space: O(Log (N))


// Constraints:
// 1 <= N, M <= 106
// 0 <= arr1i, arr2i < INT_MAX
// 1 <= K <= N+M





class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int i1 = 0, i2 = 0;
    while (i1 < n && i2 < m) {
        if (--k == 0) {
            return min(arr1[i1], arr2[i2]);
        }
        if (arr1[i1] < arr2[i2]) {
            ++i1;
        } else {
            ++i2;
        }
    }
    while (i1 < n) {
        if (--k == 0) {
            return arr1[i1];
        }
        ++i1;
    }
    while (i2 < m) {
        if (--k == 0) {
            return arr2[i2];
        }
        ++i2;
    }
}
};

// class Solution{
//     public:
//     int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {
//         vector<int>ans(arr1,arr1+n);
//         for(int i =0;i<m;++i){
//             ans.push_back(arr2[i]);
//         }
//         sort(ans.begin(),ans.end());
//         return ans[k-1];
        
//     }
// };


// int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {   
//       priority_queue<int,vector<int>,greater<int>> pq;
//       for(int i=0;i<n;i++){
//           pq.push(arr1[i]);
//       }
//       for(int i=0;i<m;i++){
//           pq.push(arr2[i]);
//       }
//       while(k-->1){
//           pq.pop();
//       }
//       return pq.top();
//     }



//Your class Solution definition here

int main()
{
    Solution sol;
    int arr1[] = {2, 3, 6, 7, 9}; //You can change the first array here
    int arr2[] = {1, 4, 8, 10}; //You can change the second array here
    int n = sizeof(arr1) / sizeof(arr1[0]); //The size of the first array
    int m = sizeof(arr2) / sizeof(arr2[0]); //The size of the second array
    int k = 5; //You can change the value of k here
    int ans = sol.kthElement(arr1, arr2, n, m, k);
    cout << "The kth element of the two sorted arrays is " << ans << endl;
    return 0;
}
