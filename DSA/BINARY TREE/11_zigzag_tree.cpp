#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

// Example 1:

// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7
// Example 2:

// Input:
//            7
//         /     \
//        9       7
//      /  \     /   
//     8    8   6     
//    /  \
//   10   9 
// Output:
// 7 7 9 8 8 6 9 10 
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 104


class Solution {
public:
    // Function to store the zig-zag order traversal of a tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        
        int normal = 1;  // this means to say print in r--->l in 1, l--->r in 0
        vector<int> ans;   //stores the ans 
        queue<Node*> q;  
        q.push(root); //pushing the first ele in tree

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;  //stores all the ele it read from the cuurent parent lvl

            for (int i = 0; i < n; i++) {     //addding all childs of current lvl ele
                
                Node* it = q.front();
                q.pop();
                temp.push_back(it->data);    //pushin the parent ele

                if (it->left)
                    q.push(it->left);     //if it has left child push it to que

                if (it->right)
                    q.push(it->right);   //same
            }

            if (!normal)   //if it is  left tp right then reverser thee temp array 
                reverse(temp.begin(), temp.end());

            ans.insert(ans.end(), temp.begin(), temp.end());   // then insert it to the back of the ans array
            normal = !normal;   //change itts direction as its lvl is over
        }
        return ans;
    }
};

// Helper function to build a sample tree for testing.
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Solution solution;
    Node* root = buildSampleTree();
    vector<int> result = solution.zigZagTraversal(root);

    // Printing the zig-zag traversal result.
    cout << "Zig-Zag Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
