#include <iostream>
#include <vector>
using namespace std;

// 1530. Number of Good Leaf Nodes Pairs

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.

// Example 1:

// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
// Example 2:

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
// Example 3:

// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].

// Constraints:

// The number of nodes in the tree is in the range [1, 210].
// 1 <= Node.val <= 100
// 1 <= distance <= 10

// Definition for a binary tree node
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
    vector<int> recur(TreeNode *root, int distance, int &cnt)
    {

        if (!root)
            return {0};

        if (!root->left && !root->right)
            return {1};

        vector<int> left = recur(root->left, distance, cnt);
        vector<int> right = recur(root->right, distance, cnt);

        for (int x : left)
        {
            for (int y : right)
            {
                if (x > 0 && y > 0)
                {
                    if (x + y <= distance)
                        cnt++;
                }
            }
        }

        vector<int> ans;
        for (int x : left)
        {
            if (x > 0 && x < distance)
            {
                ans.push_back(x + 1);
            }
        }

        for (int x : right)
        {
            if (x > 0 && x < distance)
            {
                ans.push_back(x + 1);
            }
        }

        return ans;
    }

    int countPairs(TreeNode *root, int distance)
    {

        int cnt = 0;
        recur(root, distance, cnt);

        return cnt;
    }
};

// Helper function to create a binary tree (example)
TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    Solution sol;

    // Create a binary tree
    TreeNode *root = createTree();

    // Count pairs with distance <= 3
    int distance = 3;
    int result = sol.countPairs(root, distance);

    // Output the result
    cout << "Number of leaf node pairs with distance <= " << distance << ": " << result << endl;

    return 0;
}
