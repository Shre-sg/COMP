// Lowest Common Ancestor in a Binary Tree

// Given a Binary Tree with all unique values and two nodes value, n1 and n2.
// The task is to find the lowest common ancestor of the given two nodes. We may assume that 
//either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.
// Example 1:
// Input:
// n1 = 2 , n2 = 3  
//        1 
//       / \ 
//      2   3
// Output: 1
// Explanation:
// LCA of 2 and 3 is 1.

// Example 2:
// Input:
// n1 = 3 , n2 = 4
//            5    
//           /    
//          2  
//         / \  
//        3   4
// Output: 2
// Explanation:
// LCA of 3 and 4 is 2. 
// Example 3:

// Input:
// n1 = 5 , n2 = 4
//            5    
//           /    
//          2  
//         / \  
//        3   4
// Output: 5
// Explanation:
// LCA of 5 and 4 is 5. 
// Your Task:
// You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output. 

// Expected Time Complexity:O(N).
// Expected Auxiliary Space:O(Height of Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

#include <iostream>
#include <bits/stdc++.h>
// Assuming Node structure is defined
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Assuming the Solution class is defined



//ALGo : 

class Solution {
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        if (root == nullptr) {    //if the given node is null return root its the only one lefft;
            return root;
        }

        if (root->data == n1 || root->data == n2) {  //if node has data of n2,n1 thn retunr the node itself
            return root;   //because it can lowest itself 
        }
        
        //the node is not n1,n2 then call their childern to check
        Node* LEFTSIDE = lca(root->left, n1, n2);   // calling for left
        Node* RIGHTSIDE = lca(root->right, n1, n2);  //------>right 

        if (LEFTSIDE != nullptr && RIGHTSIDE != nullptr) { //if its child is not null then parent is common to both ie retunr it
            return root;
        }
        else if (LEFTSIDE != nullptr) {    //if left is not null but right is null ie n is in left ie
            return LEFTSIDE;           //cuurent leffft will the common node
        } 
        else {            ////if left is not null but left is null ie n is in right ie        
            return RIGHTSIDE;   //cuurent right will the common node
        } 
    }
};

int main() {
    // Example tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution solution;
    
    // Find the lowest common ancestor of nodes 5 and 1
    Node* result = solution.lca(root, 5, 1);

    if (result != nullptr) {
        std::cout << "Lowest Common Ancestor: " << result->data << std::endl;
    } else {
        std::cout << "One or both nodes not found in the tree." << std::endl;
    }

    // Clean up the allocated memory (not shown in the original code)
    // Release the allocated memory in a real-world scenario
    // This is just a simple example and does not handle memory management
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
