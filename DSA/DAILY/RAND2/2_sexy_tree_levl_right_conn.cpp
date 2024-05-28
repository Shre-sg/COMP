// 117. Populating Next Right Pointers in Each Node II
// Medium

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Example 1:

// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        // Vector to hold nodes at each level
        vector<vector<Node *>> lvl;
        queue<Node *> q;
        q.push(root);

        // BFS to traverse the tree level by level
        while (!q.empty())
        {
            int size = q.size();
            vector<Node *> temp;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                temp.push_back(node);
            }

            // Add NULL at the end of each level vector
            temp.push_back(NULL);
            lvl.push_back(temp);
        }

        // Link nodes at each level
        for (int i = 0; i < lvl.size(); i++)
        {
            for (int j = 0; j < lvl[i].size() - 1; j++)
            {
                lvl[i][j]->next = lvl[i][j + 1];
            }
        }

        return root;
    }
};

void printNextPointers(Node *root)
{
    Node *start = root;
    while (start)
    {
        Node *current = start;
        while (current)
        {
            cout << current->val << "->";
            if (current->next)
            {
                cout << current->next->val << " ";
            }
            else
            {
                cout << "NULL ";
            }
            current = current->next;
        }
        cout << endl;
        // move to the next level
        if (start->left)
        {
            start = start->left;
        }
        else if (start->right)
        {
            start = start->right;
        }
        else
        {
            // find the first node of the next level
            Node *temp = start;
            while (temp && !temp->next)
            {
                temp = temp->next;
            }
            if (temp)
            {
                start = temp->next;
            }
            else
            {
                start = NULL;
            }
        }
    }
}

int main()
{
    Solution solution;

    // Create a sample tree
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    solution.connect(root);

    // Print the next pointers of each node
    printNextPointers(root);

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
