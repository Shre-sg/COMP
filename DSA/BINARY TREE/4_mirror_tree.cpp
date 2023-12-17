#include <iostream>
using namespace std;


// Given the root of a binary tree, invert the tree, and return its root.


// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Example 2:
// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:
  
// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    // Base Case
    if(root==NULL)
        return NULL;
        
    invertTree(root->left); //Call the left substree
    invertTree(root->right); //Call the right substree
        
        // Swap the nodes
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
        
    return root; // Return the root
}



int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Before Inversion: " << endl;
    cout << root->val << endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->left->left->val << " " << root->left->right->val << " " << root->right->left->val << " " << root->right->right->val << endl;

    invertTree(root);

    cout << "After Inversion: " << endl;
    cout << root->val << endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->left->left->val << " " << root->left->right->val << " " << root->right->left->val << " " << root->right->right->val << endl;

    return 0;
}
