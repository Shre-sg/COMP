#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees 
//is not more than one for all nodes of tree. 

// A height balanced tree
//         1
//      /     \
//    10      39
//   /
// 5

// An unbalanced tree
//         1
//      /    
//    10   
//   /
// 5

// Example 1:

// Input:
//       1
//     /
//    2
//     \
//      3 
// Output: 0
// Explanation: The max difference in height
// of left subtree and right subtree is 2,
// which is greater than 1. Hence unbalanced
// Example 2:

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 1
// Explanation: The max difference in height
// of left subtree and right subtree is 1.
// Hence balanced. 
// Your Task:
// You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Data of a node <= 109

// Expected time complexity: O(N)
// Expected auxiliary space: O(h) , where h = height of tree




class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node *root){
        if(root == NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        
        int ans= max(left,right)+1;
        
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff= abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
}; 

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);

    // Creating an object of the Solution class
    Solution solution;

    // Calling the isBalanced function
    if (solution.isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    // Clean up: free the allocated memory
    // (You might want to use a proper tree destruction function in a real application.)
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
