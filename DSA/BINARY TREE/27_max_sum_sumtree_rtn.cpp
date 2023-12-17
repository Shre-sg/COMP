#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Assuming Node structure is defined like this
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



// Find largest subtree sum in a tree
// Given a binary tree, task is to find subtree with maximum sum in tree.

// Examples:  

// Input :       1
//             /   \
//            2      3
//           / \    / \
//          4   5  6   7
// Output : 28
// As all the tree elements are positive,
// the largest subtree sum is equal to
// sum of all tree elements.

// Input :       1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2
// Output : 7
// Subtree with largest sum is : 
//    -2
//    / \ 
//   4   5
// Also, entire tree sum is also 7.
// Recommended : Please try your approach first on IDE and then look at the solution.
// Approach : Do post order traversal of the binary tree. At every node, find left subtree value and right subtree value recursively. The value of subtree rooted at current node is equal to sum of current node value, left node subtree sum and right node subtree sum. Compare current subtree sum with overall maximum subtree sum so far.

// Implementation :  




class Solution {
public:
    int max_ = INT_MIN;

    int postorder(Node* root) {
        if (root == NULL)
            return 0;

        int lefti = postorder(root->left);
        int righti = postorder(root->right);

        int store = root->data;
        max_ = max(max_, store + lefti + righti);

        return store + lefti + righti;
    }

    int maxSumTree(Node* node) {
        postorder(node);
        return max_;
    }
};

int main() {
    // Example tree creation
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution solution;
    int maxSum = solution.maxSumTree(root);

    cout << "Maximum sum in a subtree: " << maxSum << endl;

    // Don't forget to free the allocated memory
    // (In a real-world scenario, you would want to use smart pointers or a memory management strategy)
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
