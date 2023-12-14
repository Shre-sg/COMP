#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Check Mirror in N-ary tree
// Given two n-ary trees. Check if they are mirror images of each other or not.
// You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[].
// Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

// Example 1:
// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 3, 1, 2}
// Output:
// 1
// Explanation:
//    1          1
//  / \        /  \
// 2   3      3    2 
// As we can clearly see, the second tree
// is mirror image of the first.

// Example 2:
// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 2, 1, 3}
// Output:
// 0
// Explanation:
//    1          1
//  / \        /  \
// 2   3      2    3 
// As we can clearly see, the second tree
// isn't mirror image of the first.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function
// checkMirrorTree() which takes 2 Integers n, and e;  and two arrays A[] and B[] of size 2*e as 
//input and returns 1 if the trees are mirror images of each other and 0 if not.

//APPROACH 1:
// USING array
// 1.read the two array , push them to to map like 1---> {1,2,4,5.....so onn}
// 2.reverse the one maps vector
// 3. check if they two maps match then they are mirror img

//APPROACH 2:
// using stack
// 1. same way instea of using array we we stack and push ele we encounted to respective parent node stack
// 2. as we pop the ele array it should match with the array ele in second array if yes it ia a mirrio tree

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,vector<int>> m1,m2;
        
        for(int i = 0;i<2*e;i+=2){     ///+2 as it is a edge tree array 
            m1[A[i]].push_back(A[i+1]); 
            m2[B[i]].push_back(B[i+1]);
        }
        
        for(auto i:m1){
            reverse(i.second.begin(),i.second.end());  //sorting secoond map vector  of all the nodes 
            
            if(i.second != m2[i.first])  //check if not match thn false 
                return false;
        }
        return true;
    }
    
    //  int checkMirrorTree(int n, int e, int A[], int B[]) {
    //     //we are going to store the elemts of ach root in the stack
    //     //and in later part we are going to pop the lements from exach stack and mathch it with the original tree map
    //     //we will require map consisting of nodes and its corresponding stack
        
    //     unordered_map<int,stack<int>>mp;
        
    //     for(int i=0;i<2*e;i+=2){
    //         //we are going to map the elemts in stack
    //         mp[A[i]].push(A[i+1]);
    //         //we are pushing the nodes corrsponding to root
    //     }
        
    //     //no we need to match by popping every elemt of the stack
        
    //     for(int i=0;i<2*e;i+=2){
    //         if(mp[B[i]].top()!=B[i+1]){
    //             return 0;
    //         }
    //         mp[B[i]].pop();
            
    //     } 
        
    //     return 1;
    // }

};

int main() {
    // Example usage of the checkMirrorTree function
    Solution solution;

    // Number of nodes
    int n = 5;

    // Number of edges
    int e = 4;

    // Array A representing edges in tree 1
    int A[] = {1, 2, 1, 3, 2, 4, 2, 5};

    // Array B representing edges in tree 2
    int B[] = {1, 3, 1, 2, 2, 5, 2, 4};

    // Call the checkMirrorTree function
    int result = solution.checkMirrorTree(n, e, A, B);

    // Display the result
    if (result)
        std::cout << "Trees are mirror images." << std::endl;
    else
        std::cout << "Trees are not mirror images." << std::endl;

    return 0;
}