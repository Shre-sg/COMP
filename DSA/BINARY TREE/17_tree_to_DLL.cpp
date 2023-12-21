#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for convenience
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Binary Tree to DLL
// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and 
//right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
// The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of 
//Inorder traversal (leftmost node in BT) must be the head node of the DLL.

// TreeToList

// Example 1:
// Input:
//       1
//     /  \
//    3    2
// Output:
// 3 1 2 
// 2 1 3 
// Explanation: DLL would be 3<=>1<=>2

// Example 2:
// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60 
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
// Explanation:  DLL would be 
// 40<=>20<=>60<=>10<=>30.
// Your Task:
// You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL . The driver code prints the DLL both ways.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105



// Include the Solution class
class Solution {
public:
    // Function to convert binary tree to doubly linked list
    void inorder(Node* root, Node*& head, Node*& prev) {

        if (!root)
            return;

        inorder(root->left, head, prev);    

        if (!prev) {       //if prev is  null
            head = root;     //head does not moves around as we transverse     
        }
        else {            // if prev is not null 
            root->left = prev;   //head node left is made to prev node 
            prev->right = root;   //prev right is made to head node
        }

        prev = root; //head remains const only prev & root transverse and form a DLL   
        inorder(root->right, head, prev);
    }

    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;

        inorder(root, head, prev);

        return head;
    }
};

// Function to traverse and print the doubly linked list
void traverseDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    // Create an instance of the Solution class
    Solution solution;

    // Convert the binary tree to doubly linked list
    Node* head = solution.bToDLL(root);

    // Traverse and print the doubly linked list
    cout << "Doubly Linked List: ";
    traverseDLL(head);

    // Clean up the dynamically allocated memory
    // Note: In a real-world scenario, you should use proper memory management
    // and delete the nodes appropriately.

    return 0;
}
