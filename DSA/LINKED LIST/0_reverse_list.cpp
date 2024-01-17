#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

void printNodes(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to push nodes into the linked list
void push(struct Node **head_ref, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

// Given a linked list of N nodes. The task is to reverse this list.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5->6
// Output: 6 5 4 3 2 1
// Explanation: After reversing the list,
// elements are 6->5->4->3->2->1.
// Example 2:

// Input:
// LinkedList: 2->7->8->9->10
// Output: 10 9 8 7 2
// Explanation: After reversing the list,
// elements are 10->9->8->7->2.
// Your Task:
// The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:

// Function to reverse the nodes in the linked list
void reverse(struct Node **head_ref)
{

    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*head_ref);

    while (current != NULL)
    {
        temp = current->next; // Store the next node
        current->next = prev; // Reverse the link

        prev = current; // Move pointers one position ahead
        current = temp;
    }

    // prev is the new head after reversing the list
    (*head_ref) = prev;
}

// Driver function to check the above algorithm
int main()
{
    struct Node *head = NULL;
    push(&head, 10);
    push(&head, 11);
    push(&head, 18);
    push(&head, 60);
    push(&head, 94);
    push(&head, 100);

    cout << "List before reversing:" << endl;
    printNodes(head);

    reverse(&head);

    cout << endl;
    cout << "List after reversing:" << endl;
    printNodes(head);

    return 0;
}
