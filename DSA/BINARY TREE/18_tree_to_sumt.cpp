#include <iostream>
using namespace std;
// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for convenience
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Transform to Sum Tree

// Given a Binary Tree of size N , where each node can have positive or negative values.
// Convert this to a tree where each node contains the sum of the left and right sub trees of the 
//original tree. The values of leaf nodes are changed to 0.

// Example 1:
// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

// Explanation:

//            (4-2+12+6)
//           /           \
//       (8-4)          (7+5)
//        /   \         /  \
//       0     0       0    0
 

// Your Task:  
// You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

// Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of tree)
 

// Constraints:
// 1 ≤ N ≤ 104


// Include the Solution class
class Solution {
public:
    int postorder(Node* root) {
        if (root == NULL)
            return 0;

        int lefti = postorder(root->left);
        int righti = postorder(root->right);

        int store = root->data;
        root->data = lefti + righti;

        return store + lefti + righti;
    }

    void toSumTree(Node* node) {
        postorder(node);
        return;
    }
};




// Function to perform an inorder traversal and print the tree nodes
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    // Create an instance of the Solution class
    Solution solution;

    // Convert the binary tree to a sum tree
    solution.toSumTree(root);

    // Print the inorder traversal of the modified tree
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up the dynamically allocated memory
    // Note: In a real-world scenario, you should use proper memory management
    // and delete the nodes appropriately.

    return 0;
}
