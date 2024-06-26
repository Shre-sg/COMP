#include <iostream>
#include <vector>

using namespace std;


// 1382. Balance a Binary Search Tree

// Hint
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> sortedArr;
    
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }

    void inorderTraverse(TreeNode* root) {
        if (root == NULL) 
            return;
        
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }

    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) 
            return NULL;
        
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        
        return root;
    }
};

// Utility function to print inorder traversal of a binary tree
void printInorder(TreeNode* node) {
    if (node == NULL) 
        return;

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Utility function to create a binary tree from a vector
TreeNode* createBST(const vector<int>& arr, int start, int end) {
    if (start > end) 
        return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);

    return root;
}

int main() {
    // Input tree: Unbalanced BST
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};  // Example: already sorted array
    TreeNode* root = createBST(nodes, 0, nodes.size() - 1);

    // Create a solution object
    Solution sol;

    // Balance the BST
    TreeNode* balancedRoot = sol.balanceBST(root);

    // Print inorder traversal of the balanced BST
    cout << "Inorder traversal of balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}
