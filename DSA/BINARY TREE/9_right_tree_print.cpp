#include <iostream>
#include <vector>

using namespace std;


//Approach: 

// Create an vector data structure inside both the left and the right side view function

// Call for the recursive _left and recursive_right function respectively with the (root,level,vector).
// Here level will be initially passed as 0.

// Return the vector.

// Now in the recursive_left function
// If vector size is equal to the level then push_back its node value to the vector data structure.
// Otherwise call recursive_left for (node->left,level+1,vector)
// Call recursive_left for (node->right,level+1,vector)

// Now in the recursive_right function
// If vector size is equal to the level then push_back its node value to the vector data structure.
// Otherwise call recursive_right for (node->right,level+1,vector)
// Call recursive_right for (node->left,level+1,vector)
// Tip: The Code for the Left and the Right View is almost identical. 

// In the Right view code first, you have to call the recursive function for the right then the 
//left node




// Assuming you have a Node structure defined like this:
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Your leftView function
void solve(Node *root, vector<int>& ans, int level) {
    if (root == nullptr) {
        return;
    }

    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    solve(root->right, ans, level + 1);   ///only diffrence 
    solve(root->left, ans, level + 1);
    
}

vector<int> rightview(Node *root) {
    vector<int> ans;
    int level = 0;

    solve(root, ans, level);
    return ans;
}

// Main function to test the leftView function
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call leftView function
    vector<int> result = rightview(root);

    // Display the left view of the binary tree
    cout << "Left View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the memory (assuming you have a proper destructor for Node)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
