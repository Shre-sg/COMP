#include <iostream>
#include <string>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for convenience
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



// Construct Binary Tree from String with bracket representation
// MediumAccuracy: 59.15%Submissions: 18K+Points: 4

// Construct a binary tree from a string consisting of parenthesis and integers. The whole input 
//represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis.
// The integer represents the roots value and a pair of parenthesis contains a child binary tree with 
//the same structure. Always start to construct the left child node of the parent first if it exists.
// The integer values will be less than or equal to 10^5.

// Example 1:
// Input: "1(2)(3)" 
// Output: 2 1 3
// Explanation:
//            1
//           / \
//          2   3
// Explanation: first pair of parenthesis contains 
// left subtree and second one contains the right 
// subtree. Inorder of above tree is "2 1 3".

// Example 2:
// Input: "4(2(3)(1))(6(5))"
// Output: 3 2 1 4 5 6
// Explanation:
//            4
//          /   \
//         2     6
//        / \   / 
//       3   1 5   
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 <= |str| <= 105




// Include the Solution class
class Solution {
public:
    void f(string s, int& i, Node*& root) {
        
        if (i >= s.size()){       //if str is empty
            return;
        }
        
        string p;        //fing the number from the string 
        if (s[i] != '(' && s[i] != ')') {
            while (s[i] != '(' && s[i] != ')') {   //adding whatever text we got to str till brac comes
                p = p + s[i];   ///p has the number to be added to node data
                i++;
            }

            root = new Node(stoi(p));    // creating node for str p by coverting it inot int 
        }

        if (i < s.size() && s[i] == '(' && s[i - 1] != ')') {
            i++;
            f(s, i, root->left);    //as i is point--> to ( we increment to next text send it left root form
        }
        
        if (i < s.size() && s[i] == '(' && s[i - 1] == ')') {
            i++;
            f(s, i, root->right);     // then right root
        }
        
        if (i < s.size() && s[i] == ')') {
            i++;
            return;
        }

        return;
    }

    Node* treeFromString(string str) {
        
        Node* root = nullptr; // Initialize the root pointer to nullptr
        
        int i = 0;
        f(str, i, root);    //sending the node & str & index ref to 0th ele in str
        
        return root;
    }
};

int main() {
    // Example of a parenthesized string representing a binary tree: "1(2(4)(5))(3(6))"
    string treeString = "1(2(4)(5))(3(6))";

    // Create an instance of the Solution class
    Solution solution;

    // Construct the tree from the string
    Node* root = solution.treeFromString(treeString);

    // You can now use the 'root' pointer to perform operations on the tree.

    // Clean up the dynamically allocated memory
    // Note: In a real-world scenario, you should use proper memory management
    // and delete the nodes appropriately.

    return 0;
}
