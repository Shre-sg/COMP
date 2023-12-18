#include <iostream>

// Assuming Node structure is defined
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



// Min distance between two given nodes of a Binary Tree

// Given a binary tree and two node values your task is to find the minimum distance between them.
// The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
// Please Note that a and b are not always leaf node.

// Example 1:

// Input:
//         1
//       /  \
//      2    3
// a = 2, b = 3
// Output: 2
// Explanation: The tree formed is:
//        1
//      /   \ 
//     2     3
// We need the distance between 2 and 3.
// Being at node 2, we need to take two
// steps ahead in order to reach node 3.
// The path followed will be:
// 2 -> 1 -> 3. Hence, the result is 2. 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 105



// Assuming the Solution class is defined
class Solution {
public:
    //LCN
    Node* solve(Node* root, int a, int b) {   //it gives closest common node to given both node
        if (root == NULL) {
            return NULL;
        }

        if (root->data == a || root->data == b) {
            return root;
        }

        Node* leftAns = solve(root->left, a, b);
        Node* rightAns = solve(root->right, a, b);

        if (leftAns != NULL && rightAns != NULL) {
            return root;
        } 
        
        else if (leftAns != NULL && rightAns == NULL) {
            return leftAns;
        } 
        
        else if (leftAns == NULL && rightAns != NULL) {
            return rightAns;
        } 
        
        else {
            return NULL;
        }
    }

    int distance(Node* root, int node) {  //it calculates the shortest distance from the LCN to given node
        
        if (root == NULL) {
            return -1;
        }

        if (root->data == node) {
            return 0;   ///it retunrns zero as left node then as it travels up +1 gets added
        }

        int left = distance(root->left, node);
        int right = distance(root->right, node);

        if (left != -1) {
            return left + 1;   //returing the distance  by adding one
        }  
        else if (right != -1) {
            return right + 1;
        } 
        else {
            return -1;
        }
    }

    int findDist(Node* root, int a, int b) {
        Node* ans = solve(root, a, b);  //find the common LCN node 

        int distance1 = distance(ans, a);  ///find the shortest distance from LCN & a
        int distance2 = distance(ans, b);  /////find the shortest distance from LCN & b

        return distance1 + distance2;  //retuning the the distance between two nodes
    }
};

int main() {
    // Example tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution solution;

    // Find the distance between nodes 5 and 1
    int result = solution.findDist(root, 5, 1);

    std::cout << "Distance between nodes 5 and 1: " << result << std::endl;

    // Clean up the allocated memory (not shown in the original code)
    // Release the allocated memory in a real-world scenario
    // This is just a simple example and does not handle memory management
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
