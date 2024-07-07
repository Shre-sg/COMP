#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// 236. Lowest Common Ancestor of a Binary Tree
// Solved
// Medium
// Topics
// Companies
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [1,2], p = 1, q = 2
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the tree.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = f(root, p, q);
        return ans;
    }

    TreeNode *f(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        // base case
        if (node == NULL)
            return NULL;

        if (node == p || node == q)
            return node;

        // try out all options
        TreeNode *l = f(node->left, p, q);
        TreeNode *r = f(node->right, p, q);

        // assess and return
        if ((l == p && r == q) || (l == q && r == p)) // nodes are present in diff subtree
            return node;

        else if (l != NULL) // lca is the l or p node itself
            return l;

        else if (r != NULL) // lca is the r or q node itself
            return r;

        else
            return NULL; // i count not find nodes in tree
    }
};

// Helper function to insert nodes in the binary tree for testing
TreeNode *insertLevelOrder(vector<int> &arr, TreeNode *root, int i)
{
    if (i < arr.size())
    {
        TreeNode *temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2);
    }
    return root;
}

// Helper function to find a node by value
TreeNode *findNode(TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    TreeNode *leftResult = findNode(root->left, val);
    if (leftResult != NULL)
        return leftResult;
    return findNode(root->right, val);
}

int main()
{
    Solution solution;
    vector<int> treeValues = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode *root = insertLevelOrder(treeValues, root, 0);

    int pVal = 5, qVal = 1;
    TreeNode *p = findNode(root, pVal);
    TreeNode *q = findNode(root, qVal);

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != NULL)
    {
        cout << "The lowest common ancestor of nodes " << pVal << " and " << qVal << " is: " << lca->val << endl;
    }
    else
    {
        cout << "There is no common ancestor for nodes " << pVal << " and " << qVal << "." << endl;
    }

    return 0;
}

// arry check method
// class Solution
// {
// public:
//     void dfs(TreeNode *root, vector<TreeNode *> &P, vector<TreeNode *> &Q, TreeNode *p, TreeNode *q, bool pfound, bool qfound)
//     {
//         if (root == p)
//         {
//             P.push_back(p);
//             pfound = true;
//         }
//         else if (root == q)
//         {
//             Q.push_back(q);
//             qfound = true;
//         }

//         if (qfound && pfound)
//             return;

//         P.push_back(root);
//         Q.push_back(root);
//         if (root->left)
//             dfs(root->left, P, Q, p, q, pfound, qfound);
//         if (root->right)
//             dfs(root->right, P, Q, p, q, pfound, qfound);

//         if (!pfound)
//             P.pop_back();
//         if (!qfound)
//             Q.pop_back();
//     }
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         // case if one p is q's lca
//         vector<TreeNode *> P;
//         vector<TreeNode *> Q;
//         bool pfound = false, qfound = false;
//         dfs(root, P, Q, p, q, pfound, qfound);
//         int i = 0;

//         while (true)
//         {
//             if (*(P.begin() + i) == *(Q.begin() + i))
//             {
//                 i++;
//             }
//             else
//             {
//                 i--;
//                 break;
//             }
//         }
//         return P[i];
//     }
// };

// easy way
// class Solution
// {
// public:
//     // void print(vector<TreeNode*>&ans){

//     //     return;
//     // }
//     bool getPath(TreeNode *root, int x, vector<TreeNode *> &path)
//     {
//         if (root == NULL)
//             return false;

//         path.push_back(root);

//         if (root->val == x)
//             return true;

//         if (getPath(root->left, x, path) ||
//             getPath(root->right, x, path))
//             return true;

//         path.pop_back();
//         return false;
//     }

//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         if (root == NULL)
//             return NULL;

//         vector<TreeNode *> path1;
//         vector<TreeNode *> path2;
//         getPath(root, p->val, path1);
//         getPath(root, q->val, path2);
//         root = NULL;
//         for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
//         {
//             if (path1[i] == path2[j])
//                 root = path1[i];
//             else
//                 return root;
//         }

//         return root;
//     }
// };