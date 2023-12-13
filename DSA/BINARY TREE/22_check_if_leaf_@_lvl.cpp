#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    // Add any other necessary members
};



// Leaf at same level

// Given a Binary Tree, check if all leaves are at same level or not.

// Example 1:
// Input: 
//             1
//           /   \
//          2     3

// Output: 1

// Explanation: 
// Leaves 2 and 3 are at same level.

// Example 2:
// Input:
//             10
//           /    \
//         20      30
//        /  \        
//      10    15

// Output: 0

// Explanation:
// Leaves 10, 15 and 30 are not at same level.

// Your Task: 
// You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of tree)




class Solution {
public:
    void solve(Node* root, map<int, int>& m, int level) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            m[level] = root->data;    //found a leaf node   // value of root gets replaced
            return;
        }
        
        solve(root->left, m, level + 1); //cslling recursion
        solve(root->right, m, level + 1);
    }

    bool check(Node* root) {
        map<int, int> m;    // map is used to store the leaf ele with its height 
        int level = 0;
        solve(root, m, level);  
        return m.size() <= 1; //size has to be less or 1 to have same lvl
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node{1,
                          new Node{2, nullptr, nullptr},
                          new Node{3, nullptr, nullptr}};

    Solution solution;

    // Test whether the binary tree has only one level of nodes
    if (solution.check(root)) {
        std::cout << "The binary tree has only one level of nodes.\n";
    } else {
        std::cout << "The binary tree has more than one level of nodes.\n";
    }

    // TODO: Free the allocated memory for the tree nodes (not shown in this simple example)

    return 0;
}
