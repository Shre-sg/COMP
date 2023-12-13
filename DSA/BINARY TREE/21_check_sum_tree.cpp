#include <iostream>

// Assuming the definition of the Node structure is available
struct Node {
    int data;
    Node* left;
    Node* right;
    // Add any other necessary members
};


// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its 
//value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
//A leaf node is also considered a Sum Tree.


// Example 1:

// Input:
//     3
//   /   \    
//  1     2

// Output: 1
// Explanation:
// The sum of left subtree and right subtree is
// 1 + 2 = 3, which is the value of the root node.
// Therefore,the given binary tree is a sum tree.
// Example 2:

// Input:

//           10
//         /    \
//       20      30
//     /   \ 
//    10    10

// Output: 0
// Explanation:
// The given tree is not a sum tree.
// For the root node, sum of elements
// in left subtree is 40 and sum of elements
// in right subtree is 30. Root element = 10
// which is not equal to 30+40.

// Your Task: 
// You don't need to read input or print anything. Complete the function isSumTree() which takes root node as input parameter and returns true if the tree is a SumTree else it returns false.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of the Tree)



/// ALGo is basically  inorder traversal there by cheching the sum
class Solution {
public:
    int f(Node* root)
    {
        if(!root) 
            return 0;
         
        if(!root->left and !root->right) 
            return root->data;
         
        int left=f(root->left);
        if(left==-1) 
            return -1;
         
        int right=f(root->right);
        if(right==-1) 
            return -1;
         
        if((left+right)==root->data) 
            return left+right+root->data;
        else 
            return -1;
    }
       

    bool isSumTree(Node* root) {
        return f(root) != -1 ? true : false;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node{10, new Node{3, nullptr, nullptr}, new Node{7, nullptr, nullptr}};

    Solution solution;
    
    // Testing whether the binary tree is a Sum Tree
    if (solution.isSumTree(root)) {
        std::cout << "The binary tree is a Sum Tree.\n";
    } else {
        std::cout << "The binary tree is not a Sum Tree.\n";
    }

    // TODO: Free the allocated memory for the tree nodes (not shown in this simple example)

    return 0;
}
