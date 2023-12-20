#include <iostream>
#include <vector>

using namespace std;


// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes 
//visible when tree is visited from Left side. The task is to complete the function leftView(), 
//which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3 
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Example 1:

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3



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
    if (root == nullptr) {   //rec node is emppty just return  
         return;
    }

    if (level == ans.size()) {          //if height of tree and the coded is present push the data
        ans.push_back(root->data);      //this happens when left most node is found 
    }

    solve(root->left, ans, level + 1);       // rec call left first very impotant
    solve(root->right, ans, level + 1);     //if left node doesnt exist it goes to the right node 
}                                           ///if left node exist hight increses as it goes to right  
                                            ////node ie it does not get pushed
vector<int> leftView(Node *root) {
    vector<int> ans;
    int level = 0;   //stores the height 

    solve(root, ans, level);   //very imporant 
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
    vector<int> result = leftView(root);

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
