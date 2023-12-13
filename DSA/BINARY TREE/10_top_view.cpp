#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Assuming you have a Node structure defined somewhere.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Given below is a binary tree. The task is to print the top view of binary tree.
// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
//For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow
// of the tree and are at same position then consider the left ones only(i.e. leftmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. 
//Here 8 and 9 are on the same position but 9 will get shadowed.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3
// Example 2:

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100
// Your Task:
// Since this is a function problem. You don't have to take input. 
//Just complete the function topView() that takes root node as parameter and returns a list of 
//nodes visible from the top view from left to right.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105



// Approach: 

// First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
// Then we need a map data structure to store the lines and the nodes. This map will 
//store the data in the form of sorted orders of keys(Lines).
// Here we will follow the level order traversal.
// Traverse through the nodes starting with root,0 and store them to the queue.
// Until the queue is not empty, store the node  and line no. in 2 separate variable .
// Then check if that line is present in the map or not
// If not present then store the line and the node->val to the map
// Otherwise store the node->left and node->right along with there line nos. to the queue.
// Then print the node->val from the map





class Solution {
public:
    vector<int> topView(Node *root) {
        
        vector<int> v;
        map<int,int> m;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(q.empty()==false){
            
            auto p = q.front();   // has the node
            q.pop();
            
            Node* curr = p.first;
            int hd = p.second;          ///hols the level 0 0r -1 or 1
            
            if(m.find(hd)==m.end()){    //checking if the that lvl is present or not 
                m[hd] = curr->data;     //if not there add to the the map
            }
            
            if(curr->left!=NULL){
                q.push({curr->left,hd-1});
            }
            
            if(curr->right!=NULL){
                q.push({curr->right,hd+1});
            }
        }
        
        for(auto x : m){
            v.push_back(x.second);
        }
        
        return v;
    }
};

int main() {
    // Create a binary tree for testing
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    // Create an instance of the Solution class
    Solution solution;

    // Call the topView function
    vector<int> result = solution.topView(root);

    // Print the result
    cout << "Top View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

