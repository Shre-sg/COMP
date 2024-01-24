#include <iostream>
#include <unordered_set>

using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

// Given a linked list of N nodes such that it may contain a loop.
// A loop here means that the last node of the link list is connected to the node
// at position X(1-based index). If the link list does not have any loop, X=0.
// Remove the loop from the linked list, if it is present, i.e. unlink the last node
// which is forming the loop.

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|
// A loop is present. If you remove it
// successfully, the answer will be 1.

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not
// contains any loop.

// Example 3:

// Input:
// N = 4
// value[] = {1,2,3,4}
// X = 1
// Output: 1
// Explanation: The link list looks like
// 1 -> 2 -> 3 -> 4
// ^              |
// |______________|
// A loop is present.
// If you remove it successfully,
// the answer will be 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
// Note: The generated output will be 1 if your submitted code is correct.

// Expected time complexity: O(N)
// Expected auxiliary space: O(1)

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        Node *cur = head;
        Node *prev = NULL; // Initialize prev to NULL
        unordered_set<Node *> s;

        while (cur != NULL)
        {
            if (s.find(cur) != s.end()) // if the same node is found, there is a loop
            {
                prev->next = NULL; // i make the prev nodfe to NULL
                return;
            }

            prev = cur;
            s.insert(cur);
            cur = cur->next;
        }
    }
};

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a linked list with a loop
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution solution;
    cout << "Linked List before removing the loop: ";
    printList(head);

    // Removing the loop
    solution.removeLoop(head);

    cout << "Linked List after removing the loop: ";
    printList(head);

    return 0;
}
