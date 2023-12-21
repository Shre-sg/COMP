#include <iostream>
#include <vector>
using namespace std;
// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor for convenience
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf
// node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. 
//The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

// Example 1:

// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3
// Explanation:


 

// Example 2:

// Input:
//             1
//            /
//           2
//         /  \
//        4    9
//      /  \    \
//     6    5    3
//              /  \
//             7     8

// Output: 1 2 4 6 5 7 8
// Explanation:

// As you can see we have not taken the right subtree. 
// Your Task:
// This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

// Expected Time Complexity: O(N). 
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105





// Approach: Boundary traversal in an anti-clockwise direction can be described as a
// traversal consisting of three parts:

// Part 1: Left Boundary of the tree (excluding the leaf nodes).
// Part 2: All the leaf nodes travelled in the left to right direction.
// Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
// We take a simple data structure like a vector/Arraylist to store the Boundary Traversal. The root node is coming from both the boundaries (left and right). Therefore, to avoid any confusion, we push it on our list at the very start.


// We will now see the approach to finding these three parts.
// Part 1:  Left Boundary
// To traverse the left boundary, we can set a simple iteration. Initially, we make the cur 
//pointer point to the root’s left. In every iteration, if the cur node is not a leaf node, we print
// it. Then we always try to move left of the cur pointer. If there is no left child, then we move 
//to the right of cur and in the next iteration, again try to move to the left first. We stop
// our execution when cur is pointing to NULL. 

// Part 2: Leaf nodes
// To print the leaf nodes, we can do a simple preorder traversal, and check if the
// current node is a leaf node or not. If it is a leaf node just print it.
// Please note that we want the leaves to come in a specific order which is bottom-left to
// top-right, therefore a level order traversal will not work because it will print the 
//upper-level leaves first. Therefore, we use a preorder traversal.

// Part 3: Right Boundary
// We need to print the right boundary in the Reverse direction. It is very similar to the left 
//boundary traversal. We initialize our cur pointer to the right child of the root node and 
//set an iterative loop. To achieve the reverse direction, we take an auxiliary list. In
// every iteration, we check if the current node is not a leaf node then we push it to the 
//auxiliary list. Then we first try to move right of cur, if there is no right child only 
//then we move left. We stop our execution once cur points to NULL.

// Now the auxiliary list contains the nodes of the right boundary. We iterate from the 
//end to start off this list and in every iteration, push the value to our main boundary 
//traversal list. This way we get the nodes in the reverse direction.




//reCUR
class Solution {
public:
    bool isLeaf(Node* root){
      return (!root->left && !root->right);
    }
    
    void addLeft(Node * root,vector<int> &ans )
    {
        if(!root || isLeaf(root))  //retunr is no there 
        {
            return;
        }
        
        if(!isLeaf(root))
        {
            ans.push_back(root->data);
        }
        
        if(root->left) 
            addLeft(root->left,ans);
        else
            addLeft(root->right,ans);
    }
    
    void addRight(Node * root,vector<int> &temp )
    {
        if(!root || isLeaf(root))
        {
            return;
        }
        
        if(!isLeaf(root))
        {
            temp.push_back(root->data);
        }
        
        if(root->right) 
        
            addRight(root->right,temp);
        else
            addRight(root->left,temp);
    }
    
    void addLeaf(Node* root,vector<int> &ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)
            addLeaf(root->left,ans);
        if(root->right)
            addLeaf(root->right,ans);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        vector<int> temp;
        
        if(!root)
          return ans;
        
        if(!isLeaf(root)) 
            ans.push_back(root->data);
        
        addLeft(root->left,ans); //adding the left ones 
        addLeaf(root,ans);  //send root we searxh leaf and add it to the leaf
        addRight(root->right,temp);  //sending temp; so that we can reverse later
        
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
}; 



int main() {
    // Create a sample tree
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    // Create an instance of the Solution class
    Solution solution;

    // Get the boundary nodes using the boundary function
    vector<int> result = solution.boundary(root);

    // Print the result
    cout << "Boundary nodes are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    // Note: In a real-world scenario, you should use proper memory management
    // and delete the nodes appropriately.
    
    return 0;
}
