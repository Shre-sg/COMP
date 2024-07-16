#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2096. Step-By-Step Directions From a Binary Tree Node to Another

// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

// Example 1:

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:

// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue

class Solution
{
public:
    static TreeNode *LCA(TreeNode *root, int x, int y)
    {
        if (root == NULL || root->val == x || root->val == y)
            return root;

        TreeNode *l = LCA(root->left, x, y);

        TreeNode *r = LCA(root->right, x, y);
        if (l == NULL)
            return r;

        if (r == NULL)
            return l;

        return root;
    }

    static bool dfs(TreeNode *root, int x, string &path, bool rev = false)
    {
        if (root == NULL)
            return false;

        if (root->val == x)
            return true;
        // Try to find the node in the left subtree
        path.push_back(rev ? 'U' : 'L');
        if (dfs(root->left, x, path, rev))
            return true;
        path.pop_back(); // Backtrack if not found

        // Try to find the node in the right subtree
        path.push_back(rev ? 'U' : 'R');
        if (dfs(root->right, x, path, rev))
            return true;
        path.pop_back(); // Backtrack if not found

        return false;
    }

    static string getDirections(TreeNode *root, int startValue, int destValue)
    {
        root = LCA(root, startValue, destValue);

        string pathFrom = "", pathTo = "";
        dfs(root, startValue, pathFrom, true);
        dfs(root, destValue, pathTo);

        return pathFrom + pathTo;
    }
};

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int startValue = 1;
    int destValue = 6;

    string directions = Solution::getDirections(root, startValue, destValue);
    cout << "Directions: " << directions << endl; // Expected output: "UUUR"

    // Clean up the tree nodes to avoid memory leaks
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
