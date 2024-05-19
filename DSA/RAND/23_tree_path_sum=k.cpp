// 113. Path Sum II
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Example 1:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
// Example 2:

// Input: root = [1,2,3], targetSum = 5
// Output: []
// Example 3:

// Input: root = [1,2], targetSum = 0
// Output: []

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
    void rec(TreeNode *root, int target, int cur, vector<int> ds, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        cur += root->val;
        ds.push_back(root->val);
        if (root->left == NULL && root->right == NULL && cur == target)
        {
            ans.push_back(ds);
            return;
        }
        rec(root->left, target, cur, ds, ans);
        rec(root->right, target, cur, ds, ans);
        cur -= root->val; // this line is actually not needed
        ds.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        if (root == NULL)
            return ans;
        rec(root, target, 0, ds, ans);
        return ans;
    }
};

TreeNode *buildTree(vector<int> nodes, int nullVal = INT_MAX)
{
    if (nodes.empty() || nodes[0] == nullVal)
        return NULL;

    TreeNode *root = new TreeNode(nodes[0]);
    vector<TreeNode *> nodeQueue = {root};
    int i = 1;

    while (i < nodes.size())
    {
        TreeNode *curr = nodeQueue.front();
        nodeQueue.erase(nodeQueue.begin());

        if (nodes[i] != nullVal)
        {
            curr->left = new TreeNode(nodes[i]);
            nodeQueue.push_back(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != nullVal)
        {
            curr->right = new TreeNode(nodes[i]);
            nodeQueue.push_back(curr->right);
        }
        i++;
    }
    return root;
}

void printResult(const vector<vector<int>> &result)
{
    for (const auto &path : result)
    {
        cout << "[";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << path[i];
            if (i != path.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}

int main()
{
    Solution sol;
    vector<int> treeNodes = {5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, 5, 1};
    int targetSum = 22;
    TreeNode *root = buildTree(treeNodes);
    vector<vector<int>> result = sol.pathSum(root, targetSum);
    printResult(result);
    return 0;
}
