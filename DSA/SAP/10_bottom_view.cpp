// Bottom view of a Binary Tree

// Problem Statement: Given a Binary Tree, return its Bottom View. The Bottom View of a Binary Tree is the set of nodes visible when we see the tree from the bottom.

// Examples
// Example 1:
// Input:Binary Tree: 1 2 3 4 10 9 11 -1 5 -1 -1 -1 -1 -1 -1 -1 6

// Output:Bottom View Traversal: [4, 5, 6, 3, 11]
// Explanation: The bottom view of the binary tree would comprise of the nodes that are the last encountered nodes for each vertical index.

// Example 2:
// Input:Binary Tree: 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1

// Output : Bottom View: [2 5 6 11 4 9]
// Explanation:

// Disclaimer: Don’t jump directly to the solution, try it out yourself first.

// Optimal Approach
// Algorithm / Intuition
// To imagine the Binary Tree from above, we visualise vertical lines passing through the tree. Each vertical line represents a unique vertical position. Nodes to the right of the tree’s centre are assigned positive vertical indexes. As we move to the right, the vertical index increases. Nodes to the left of the tree’s centre are assigned negative vertical indexes. As we move to the left, the vertical index decreases.

// We use a map data structure to store the nodes corresponding to each vertical level of the tree as the map automatically sorts the elements based on their ascending value. Against each vertical level, the node lowest in the tree at that vertical level is added by traversing the tree level order wise (BFS).

// Algorithm:

// Step 1: Create a vector `ans` to store the result. Check if the tree is empty. If it is, return an empty vector.

// Step 2: Create a map to store the top view of nodes based on their vertical positions. The key of this map is the vertical index and the value is the node’s data.

// Step 3:Initialise a queue to perform breadth first traversal. Each element of this queue is the node of the binary tree along with its vertical coordinate. Enqueue the root node into the queue with its vertical position initialised to 0.

// Step 4: While the queue is not empty, pop the front node of the queue and for this node:

// Get its vertical position. If this vertical position is not in the map, add the node’s data to the map. This means that this node is the first node encountered at this vertical position during the traversal.
// If the vertical position of this node is already a key in the map, it implies that a node higher in the tree with the same vertical position has already been processed. Overwrite this position with the current node as we want to get the lowest node of that vertical index.
// Enqueue the left child with a decreased vertical position ie. current vertical index -1. As when we move to the left child, we are moving towards the left column in the vertical order traversal.
// Enqueue the right child with an increased vertical position ie. current vertical index + 1. As when we move to the right child, we are moving towards the right column in the vertical order traversal.

// Step 5: Iterate over the map and push the values of each node into the top view traversal.

// Since the keys of the map are sorted based on their keys (vertical positions), the nodes added to the `ans` vector will be sorted left to right.
// Return the ‘ans’ vector.

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to return the
    // bottom view of the binary tree
    vector<int> bottomView(Node *root)
    {

        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> mpp; //<line,data>
        queue<pair<Node *, int>> q;

        q.push({root, 0}); //<node,line>

        // BFS traversal
        while (!q.empty())
        {

            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            mpp[line] = node->data; // for top view if put this  if only ele in not found add it to map or not

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Bottom View traversal
    vector<int> bottomView =
        solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottomView)
    {
        cout << node << " ";
    }

    return 0;
}
