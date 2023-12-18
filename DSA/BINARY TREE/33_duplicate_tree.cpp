#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a new Node
Node* createNode(int value) {
    return new Node(value);
}


// Duplicate Subtrees
// MediumAccuracy: 23.98%Submissions: 38K+Points: 4

// Given a binary tree of size N, your task is to that find all duplicate subtrees from the 
//given binary tree.

// Note: Here's the Output of every Node printed in the Pre-Order tree traversal format. 
//Arrange nodes in the answer array based on the lexicographically increasing order of their 
//preorder traversal of subtree.
// For Example: if we have 3 preorder traversal as {1,2,3},{1},{11,2,3} then your lexicographically 
//increasing order is {1},{1,2,3},{11,2,3}, you are supposed to output the head of all these subtrees 
//in the same order.

// Example:

// Input : 
    //         1
    //       /   \
    //      2     3
    //     /     /  \
    //    4     2    4
    //         /
    //        4

// Output : 2 4
//          4
// Explanation: Above Trees are two 
// duplicate subtrees.i.e  and 
// Therefore,you need to return above trees 
// root in the form of a list.
// Your Task:
// You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.


// Constraints:
// 1<=T<=100
// 1<=N<=100



string preorder(Node* root,vector<Node*>& ans,unordered_map<string,int>& mp){
    
    if(root == NULL){
        return "N";
    }
    
    string curr = to_string(root->data);  
    
    string l = preorder(root->left,ans,mp);   //retuns what fin vale we got from lrft child
    string r = preorder(root->right,ans,mp);  //retunrs what fin alue we got from right child
    
    string fin = curr+","+l+","+r;   // fin vakue calculated
    
    if(mp[fin] == 1){     //happens if the fin is alread in map   
        ans.push_back(root); //found duplicate
    }
    
    mp[fin]++;    //add the fin to map
    return fin;
}

vector<Node*> printAllDups(Node* root)
{
    vector<Node*> ans;  //store ans
    unordered_map<string,int> mp;  
    preorder(root,ans,mp);
    return ans;
}




int main() {
    // Create a sample binary tree with duplicates
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(2); // Duplicate
    root->right->left = createNode(4); // Duplicate
    root->right->right = createNode(3); // Duplicate

    // Example usage of printAllDups function
    vector<Node*> duplicates = printAllDups(root);

    cout << "Nodes with duplicates: ";
    for (const auto& node : duplicates) {
        cout << node->data << " ";
    }
    cout << endl;

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
