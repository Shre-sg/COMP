// 129. Sum Root to Leaf Numbers
// Solved
// Medium
// Topics
// Companies
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

// Example 1:

// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:

// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.

#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, long num, long &sum)
    {
        // base
        if (!root)
            return;

        // do work
        num += root->val;
        if (!root->left && !root->right)
            sum += num;

        inorder(root->left, num * 10, sum);  // left
        inorder(root->right, num * 10, sum); // right
    }

    int sumNumbers(TreeNode *root)
    {
        long num = 0, sum = 0;
        inorder(root, num, sum);
        return sum;
    }
};

// Helper function to create a new tree node
TreeNode *newNode(int val)
{
    TreeNode *node = new TreeNode(val);
    return node;
}

int main()
{
    Solution solution;

    // Create a sample tree
    //       1
    //      / \
    //     2   3
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int result = solution.sumNumbers(root);
    std::cout << "Sum of all numbers formed by root-to-leaf paths: " << result << std::endl;

    // Clean up the allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
