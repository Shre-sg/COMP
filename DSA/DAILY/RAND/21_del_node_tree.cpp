#include <iostream>

using namespace std;

// 1325. Delete Leaves With a Given Value

// Given a binary tree root and an integer target, delete all the leaf nodes with value target.

// Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

// Example 1:

// Input: root = [1,2,3,2,null,2,4], target = 2
// Output: [1,null,3,null,4]
// Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left).
// After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
// Example 2:

// Input: root = [1,3,3,3,2], target = 3
// Output: [1,3,null,null,2]
// Example 3:

// Input: root = [1,2,null,2,null,2], target = 2
// Output: [1]
// Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// 1 <= Node.val, target <= 1000

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
            return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (!root->left && !root->right && root->val == target)
            return nullptr;
        return root;
    }
};

// Helper function to print the tree in-order (for testing)
void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    Solution sol;

    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    int target = 2;

    cout << "Original tree in-order: ";
    printInOrder(root);
    cout << endl;

    root = sol.removeLeafNodes(root, target);

    cout << "Tree after removing leaf nodes with target value " << target << " in-order: ";
    printInOrder(root);
    cout << endl;

    // Clean up allocated memory (optional, for completeness)
    // In real applications, a proper tree destructor should be implemented to avoid memory leaks
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
