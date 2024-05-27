#include <iostream>

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// . Convert Sorted List to Binary Search Tree
// Medium
// Topics
// Companies
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
// height-balanced
//  binary search tree.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        // Base case: If the head is null, return null
        if (!head)
            return nullptr;

        // Initialize pointers for finding the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        // Move slow and fast pointers to find the mid point
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Create a new TreeNode with the value of the mid point
        TreeNode *root = new TreeNode(slow->val);

        // If there is only one node in the linked list, return root
        if (slow == head)
            return root;

        // Split the linked list into two halves, disconnecting at the mid point
        prev->next = nullptr;

        // Recursively construct left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// Function to print the inorder traversal of a binary tree (for testing purposes)
void inorderTraversal(TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    Solution solution;
    TreeNode *root = solution.sortedListToBST(head);

    std::cout << "Inorder traversal of constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    delete root;

    return 0;
}

// TreeNode* BST(vector<int>& v){
//     if(v.size()==0) return NULL;
//     if(v.size()==1) return new TreeNode(v[0]);

//     int mid = v.size()/2;
//     TreeNode* root= new TreeNode(v[mid]);

//     vector<int> leftTree(v.begin(),v.begin()+mid);
//     vector<int> rightTree(v.begin()+mid+1,v.end());

//     root->left = BST(leftTree);
//     root->right = BST(rightTree);

//     return root;
// }

// TreeNode* sortedListToBST(ListNode* head) {
//     ListNode* temp=head;
//     vector<int> v;
//     // Converting LinkedList into array
//     while(temp){
//         v.emplace_back(temp->val);
//         temp=temp->next;
//     }
//     if(v.size()==0) return NULL;
//     if(v.size()==1) return new TreeNode(v[0]);
//     return BST(v);
// }