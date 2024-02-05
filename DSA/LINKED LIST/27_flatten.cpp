#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int val) : data(val), next(NULL), bottom(NULL) {}
};

// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
// For more clarity have a look at the printList() function in the driver code.

// Example 1:

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     |
// 7     20    22   35
// |           |     |
// 8          50    40
// |                 |
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation:
// The resultant linked lists has every
// node in a single level.
// (Note: | represents the bottom pointer.)

// Example 2:

// Input:
// 5 -> 10 -> 19 -> 28
// |          |
// 7          22
// |          |
// 8          50
// |
// 30
// Output: 5->7->8->10->19->22->28->30->50
// Explanation:
// The resultant linked lists has every
// node in a single level.

// (Note: | represents the bottom pointer.)

// Your Task:
// You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

// Expected Time Complexity: O(N*N*M)
// Expected Auxiliary Space: O(N)

// Function to flatten and sort the linked list
Node *flatten(Node *root)
{
    // Store the values in a vector
    vector<int> v;
    while (root != NULL)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->bottom;
        }
        root = root->next;
    }

    // Sort the vector
    sort(v.begin(), v.end());

    // Create a new linked list with sorted values
    Node *z = NULL;
    Node *ans = NULL;

    for (int i = 0; i < v.size(); i++)
    {
        if (z == NULL)
        {
            z = new Node(v[i]);
            ans = z;
        }
        else
        {
            z->bottom = new Node(v[i]);
            z = z->bottom;
        }
    }

    return ans;
}

// Utility function to print the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

int main()
{
    // Sample usage
    Node *root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next->bottom = new Node(20);

    root->next->next->bottom = new Node(22);
    root->next->next->next->bottom = new Node(35);

    // Flatten and sort the linked list
    Node *flattened = flatten(root);

    // Print the sorted linked list
    cout << "Sorted Linked List: ";
    printList(flattened);

    return 0;
}
