#include <iostream>
#include <climits>

// Assuming Node structure is defined somewhere
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Sum of nodes on the longest path from root to leaf node
// MediumAccuracy: 52.39%Submissions: 65K+Points: 4

// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(),
// that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes 
//is being considered.

// Example 1:

// Input: 
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3    
//       /
//      6
// Output: 13
// Explanation:
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3 
//       /
//      6

// The highlighted nodes (4, 2, 1, 6) above are 
// part of the longest root to leaf path having
// sum = (4 + 2 + 1 + 6) = 13
// Example 2:

// Input: 
//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7
// Output: 11
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 104





//APPRROACH is preorder and also postoder can be used 
//bascially traverse the tree calcculate the sum of traversal note its sum and level 
//if lvl is more than prev lvl  update maxsum;

class Solution {
public:
    int maxSum = INT_MIN;
    int maxLen = 0;

    void solve(Node* root, int sum, int len) {
        if (root == nullptr) {   //base case of pre order
            if (len > maxLen) {   //update is sum is level is high 
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {     ///if same level updaate sum again
                maxSum = std::max(maxSum, sum);
            }
            return;
        }

        sum += root->data;   //calculating sum
        solve(root->left, sum, len + 1);    //recusive call with lvl+1;
        solve(root->right, sum, len + 1);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int sum = 0;  ///stores the current sum
        int len = 0;   //stores the current level
        solve(root, sum, len);
        return maxSum;
    }
};



int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(7);

    Solution solution;

    // Call the sumOfLongRootToLeafPath function
    int result = solution.sumOfLongRootToLeafPath(root);

    // Display the result
    std::cout << "Sum of the longest root-to-leaf path: " << result << std::endl;

    return 0;
}
