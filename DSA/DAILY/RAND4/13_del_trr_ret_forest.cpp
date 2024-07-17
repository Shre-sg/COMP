#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

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

// 1110. Delete Nodes And Return Forest

// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.

// Example 1:
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]

// Example 2:
// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]

// Constraints:
// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.

class Solution
{
    vector<TreeNode *> res;
    unordered_set<int> st;

    void deleteNode(TreeNode *&root)
    {
        if (root)
        {
            deleteNode(root->left);
            deleteNode(root->right);
            if (st.find(root->val) != st.end())
            {
                if (root->left)
                    res.push_back(root->left);
                if (root->right)
                    res.push_back(root->right);
                root = nullptr;
            }
        }
        return;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        for (int i = 0; i < to_delete.size(); i++)
        {
            st.insert(to_delete[i]);
        }

        deleteNode(root);

        if (root)
            res.push_back(root);
        return res;
    }
};

// Utility function to print the tree nodes in pre-order traversal
void printPreorder(TreeNode *node)
{
    if (node == nullptr)
        return;

    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    // Example usage:
    Solution solution;

    // Creating a sample tree:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Nodes to delete
    vector<int> to_delete = {3, 5};

    // Deleting nodes
    vector<TreeNode *> remainingForest = solution.delNodes(root, to_delete);

    // Printing the remaining trees
    cout << "Remaining trees in the forest:" << endl;
    for (TreeNode *tree : remainingForest)
    {
        printPreorder(tree);
        cout << endl;
    }

    return 0;
}
