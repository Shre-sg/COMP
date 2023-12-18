#include <iostream>
#include <unordered_map>

using namespace std;

// Assuming Node structure is defined
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Maximum sum of nodes in Binary tree such that no two are adjacent

// Given a binary tree with a value associated with each node, we need to choose a subset of
//  these nodes such that the sum of selected nodes is maximum under a constraint that no two chosen 
//  nodes in the subset should be directly connected, that is, if we have taken a node in our sum then 
//  we can’t take any of its children in consideration and vice versa



// Explanation: In the above binary tree, chosen nodes are encircled and are not directly
// connected, and their sum is the maximum possible
// Recommended: Please solve it on “PRACTICE” first before moving on to the solution.

// The maximum sum of nodes in a Binary tree such that no two are adjacent using Recursion:
// We can solve this problem by considering the fact that both node and its 
//children can’t be in sum at the same time, so when we take a node into our sum, we will call recursively for its grandchildren or if we don’t take this node then we will call for all its children nodes and finally we will choose maximum from both of the results. 

// It can be seen easily that the above approach can lead to solving the 
//same subproblem many times, for example in the above diagram node 1 calls node 4 and 5 when 
//its value is chosen and node 3 also calls them when its value is not chosen so these nodes 
//are processed more than once. We can stop solving these nodes more than once by memorizing 
//the result at all nodes

// Follow the below steps to solve the problem:

// Create a map to memorize the results
// Recur to solve the problem for the root node
// If the root is NULL return 0 (Base Case)
// If the answer to this subproblem is already stored in the map, then return it
// Now either include the current node and recur for its grandchildren 
// or don’t take the current node and recur for its left and the right child
// Save the answer to this problem equal to the maximum of the above two cases
// Return the answer
// Below is the implementation of the above approach:





// algo https://youtu.be/DBxCv9NpPYM?si=UYnrlfTpdRk9WHUi

unordered_map<Node*, int> m;

//unordered map is used to optamise the code to reduce time 

int getMaxSum(Node* root) {
    if (!root) 
        return 0;
    
    if (m[root]) 
        return m[root];

    int withNode = root->data;   //if we count the cuurent node

    if (root->left) {    //we cant take the chid ie the adjacent nodes
        withNode += getMaxSum(root->left->left);    //ie counting the non adjaceent nodes of its left child
        withNode += getMaxSum(root->left->right);
    }

    if (root->right) {     
        withNode += getMaxSum(root->right->left);   //ie counting the non adjaceent nodes of its right child
        withNode += getMaxSum(root->right->right);
    }

    int withoutNode = getMaxSum(root->left) + getMaxSum(root->right); 
    //if we dont take the node no need to count the root->.data ie we are couning the sum of the childs
    ///then this child has a choice to take their node or not again in recursion
    return m[root] = max(withNode, withoutNode);  //now whateever we get max of choosing the current node 
                            //or not then mapping it in map  to save time
}

int main() {
    // Example tree
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << "Maximum sum is: " << getMaxSum(root) << endl;

    // Clean up the allocated memory (not shown in the original code)
    // Release the allocated memory in a real-world scenario
    // This is just a simple example and does not handle memory management
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
