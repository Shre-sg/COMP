

#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete 
//the function kthAncestor(), the function should return the kth ancestor of the given node 
//in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Example 1:



// Input:
// K = 2 Node = 4
// Output: 1
// Explanation:
// Since, K is 2 and node is 4, so we
// first need to locate the node and
// look k times its ancestors.
// Here in this Case node 4 has 1 as his
// 2nd Ancestor aka the Root of the tree.
// Example 2:

// Input:
// k=1 
// node=3
//       1
//     /   \
//     2     3

// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.
// Your Task:
// You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input parameters, and returns the kth ancestor of Node which contains node as its value.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<=N<=105
// 1<= K <= 100
// 1 <= Node.data <= N




//Here, instead of 'values' vector to store ancestor node-values , 
//we'll be having 'cnt' variable to track of ancestors encountered and 'val' variable to store
// final kth ancestor value.

//We'll update 'val' variable only when 'cnt' becomes 0 because that will tell us that
// we are currently on the kth ancestor. Also , 'cnt' variable will only be updated once we find
// node with the given value as we'll be returning 1  , else 0.

//Here, 'cnt' variable is passed by reference to keep track of ancestors encountered and we
// don't want to lose it when coming back from recusive calls. Also 'val' variable is passed by 
///reference to store the value of kth ancestor value if found , and we don't want to lose it in
// recursive calls.
//Traversal would be simply ' Preorder ' with slight variation.
// Function to create a new Node
Node* createNode(int value) {
    return new Node(value);
}

bool solve(Node* root, int& cnt, int& node, int& val) {
    if (root == nullptr) return false;

    if (root->data == node) {
        return true;
    }
    int l = solve(root->left, cnt, node, val);

    int r = solve(root->right, cnt, node, val);

    if (l || r) {
        cnt--;
        if (cnt == 0) val = root->data;

        return true;
    }

    return false;
}

int kthAncestor(Node* root, int k, int node) {
    int cnt = k;
    int val = -1;

    solve(root, cnt, node, val);

    return val;
}

int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Example usage of kthAncestor function
    int k = 2;   // Replace with the desired value of k
    int node = 5; // Replace with the desired value of node

    int result = kthAncestor(root, k, node);

    if (result != -1) {
        cout << "The " << k << "th ancestor of node " << node << " is: " << result << endl;
    } else {
        cout << "Node or ancestor not found." << endl;
    }

    // Clean up: delete the dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
