#include <iostream>
#include <vector>
using namespace std;

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
        // find LCA of BT
        // find path uppto that see the last common ig? extra SC is the dikkt
        // another way is a recursive way to travel...left right jate jao pr agr null mil gya toh return null if you found one of the nodes return that number if at any point you found both of the numbers returned to that node that is the lca return from there strighlty
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