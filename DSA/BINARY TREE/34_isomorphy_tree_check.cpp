#include <iostream>

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Given two Binary Trees. Check whether they are Isomorphic or not.

// Note: 
// Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
// For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
// ISomorphicTrees

// Example 1:

// Input:
//  T1    1     T2:   1
//      /   \        /  \
//     2     3      3    2
//    /            /
//   4            4
// Output: No

// Example 2:

// Input:
// T1    1     T2:    1
//     /  \         /   \
//    2    3       3     2
//   /                    \
//   4                     4
// Output: Yes
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isomorphic() that takes the root nodes of both the Binary Trees as its input and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, otherwise false.)

// Expected Time Complexity: O(min(M, N)) where M and N are the sizes of the two trees.
// Expected Auxiliary Space: O(min(H1, H2)) where H1 and H2 are the heights of the two trees.

// Constraints:
// 1<=Number of nodes<=105


//approach
// We simultaneously traverse both trees. Let the current internal nodes of two trees being traversed be n1 and n2 respectively. There are following two conditions for subtrees rooted with n1 and n2 to be isomorphic. 

// Data of n1 and n2 is same. 
// One of the following two is true for children of n1 and n2 
// ……a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2. 
// ……b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.


class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL && root2==NULL)  //no node true
            return true;
    
        if(root1==NULL || root2==NULL)  //obiously 
            return false;
    
        if(root1->data!=root2->data) 
            return false;
        else
        {
            return ( isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right) ) 
            || ( isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left) );
        }
    
    }

};

int main() {
    // Create the first tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Create the second tree
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the isIsomorphic function and print the result
    if (solution.isIsomorphic(root1, root2)) {
        std::cout << "The trees are isomorphic." << std::endl;
    } else {
        std::cout << "The trees are not isomorphic." << std::endl;
    }

    // Don't forget to free the memory allocated for the trees
    // (you might want to use a separate function for this in a real program)

    return 0;
}
