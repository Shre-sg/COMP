
#include <iostream>
#include <vector>
#include <queue>
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

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        // Call DFS to populate the right side view
        DFS(root, 0, result);
        // Alternatively, call BFS for the same purpose
        // BFS(root, result);
        return result;
    }

private:
    // DFS approach
    void DFS(TreeNode *node, int level, vector<int> &result)
    {
        if (!node)
            return;

        // If current level corresponds to the size of the result vector, add the rightmost node value
        if (level == result.size())
        {
            result.push_back(node->val);
        }

        // Traverse right first so that the rightmost node at each level is visited first
        DFS(node->right, level + 1, result);
        DFS(node->left, level + 1, result);
    }

    // BFS approach
    void BFS(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int rightmost;

            // Traverse each level
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // Update rightmost node value
                rightmost = node->val; // important

                // Push left and right children into queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // After traversing the level, add the rightmost value to the result
            result.push_back(rightmost);
        }
    }
};

// Utility function to create a binary tree from an array representation
TreeNode *createTree(vector<int> &nodes, int index)
{
    TreeNode *root = nullptr;
    if (index < nodes.size())
    {
        if (nodes[index] == -1)
            return nullptr;

        root = new TreeNode(nodes[index]);
        root->left = createTree(nodes, 2 * index + 1);
        root->right = createTree(nodes, 2 * index + 2);
    }
    return root;
}

// Utility function to delete a binary tree
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function to test the Solution
int main()
{
    Solution sol;

    // Example usage:
    vector<int> nodes = {1, 2, 3, -1, 5, -1, 4};
    TreeNode *root = createTree(nodes, 0);

    vector<int> result = sol.rightSideView(root);

    // Print the right side view
    cout << "Right Side View: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up
    deleteTree(root);

    return 0;
}
