#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;



// Minimum swap required to convert binary tree to binary search tree

// Given the array representation of Complete Binary Tree i.e, if index i is the parent, 
//index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the
// minimum number of swap required to convert it into Binary Search Tree.

// Examples:  
// Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
// Output : 3
// Binary tree of the given array:
// dig11

// Swap 1: Swap node 8 with node 5.
// Swap 2: Swap node 9 with node 10.
// Swap 3: Swap node 10 with node 7.
// dig21

// So, minimum 3 swaps are required.
// Input : arr[] = { 1, 2, 3 }
// Output : 1
// Binary tree of the given array:
// dig3

// After swapping node 1 with node 2.
// dig41

// So, only 1 swap required.
// Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.

// Approach :

// The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order 
//of their value. 
// So, find the inorder traversal of the Binary Tree and store it in the array and try to 
//sort the array. The minimum number of swap required to get the array sorted will be the answer.


//algo is basically reading the ele from treee then put it inside a vector
class Solution {
public:
    vector<int> in;

    void inorder(vector<int> &nums, int i) {
        if (i >= nums.size())
            return;

        inorder(nums, 2 * i + 1);
        in.push_back(nums[i]);
        inorder(nums, 2 * i + 2);

        return;
    }

    int minSwaps(vector<int> &A, int n) {
        
        inorder(A, 0);

        vector<pair<int, int>> temp; //stores the <value, index>
        for (int i = 0; i < n; i++)
            temp.push_back({in[i], i});

        sort(temp.begin(), temp.end());//we sort the arr accodint to the value

        //here after sorting in how many steps i can get originall vetor back ie min swaps

        int swap_cnt = 0;

        for (int i = 0; i < n; i++) {
            while (temp[i].second != i) {      //comparing index
                swap(temp[i], temp[temp[i].second]);
                swap_cnt++;
            }
        }
        return swap_cnt;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {4, 2, 5, 1, 3};
    int n = nums.size();

    int result = solution.minSwaps(nums, n);

    cout << "Minimum number of swaps required: " << result << endl;

    return 0;
}
