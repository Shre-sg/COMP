#include <iostream>
#include <cmath>
using namespace std;

// 979. Distribute Coins in Binary Tree
// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

// Example 1:

// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
// Example 2:

// Input: root = [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

// Constraints:

// The number of nodes in the tree is n.
// 1 <= n <= 100
// 0 <= Node.val <= n
// The sum of all Node.val is n.

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
    int moves = 0;

    int distributeCoins(TreeNode *root)
    {
        postOrderTraversal(root);
        return moves;
    }

    int postOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int left = postOrderTraversal(node->left);
        int right = postOrderTraversal(node->right);

        moves += abs(left) + abs(right);
        return node->val - 1 + left + right;
    }
};

int main()
{
    // Construct the tree: [3,0,0]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    // Create a Solution object and call distributeCoins
    Solution solution;
    int result = solution.distributeCoins(root);

    // Output the result
    cout << "Minimum number of moves: " << result << endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
