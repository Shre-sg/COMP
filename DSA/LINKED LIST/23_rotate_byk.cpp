// C++ code to rotate doubly linked list by N nodes
#include <bits/stdc++.h>
using namespace std;

// Class to create the nodes of the doubly linked list
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to add nodes in beginning of the linked list
void addNode(Node **head_ref, int val)
{
    Node *new_node = new Node(val);
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node->next != NULL)
    {
        if (node->next != NULL)
        {
            cout << node->data << " <-> ";
        }
        else
        {
            cout << node->data << endl;
        }
        node = node->next;
    }
    cout << node->data;
}

// Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes.
// Here N is a given positive integer and is smaller than the count of nodes in linked list.
//  Examples:

// Input : a  b  c  d  e   N = 2
// Output : c  d  e  a  b

// Input : a  b  c  d  e  f  g  h   N = 4
// Output : e  f  g  h  a  b  c  d

// Function to rotate doubly linked list by N nodes
Node *rotate(Node *head, int N)
{
    // If we have to rotate by zero nodes, then return the head node as it is
    if (N == 0)
        return head;

    // Creating a node to point the last node of the linked list
    Node *last_node = head;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    /*
           Join the first and last node by making the first node the next
            of the last node and the last node as prev of the first node
    */
    last_node->next = head;
    head->prev = last_node;

    // Variable used to go to the Nth node
    int cnt = 0;
    while (cnt < N)
    {
        head = head->next;
        last_node = last_node->next;
        cnt++;
    }

    /*
      Now head and last_node is pointing to the first and last node of
      the rotated inked, so now remove the link between head and last node
    */
    last_node->next = NULL;
    head->prev = NULL;

    // Finally, return the head node of the rotated linked list
    return head;
}

int main()
{
    /*
      Create the doubly linked list, which is to be rotated
      counterclockwise by N nodes
    */
    Node *head = NULL;
    addNode(&head, 2);
    addNode(&head, 5);
    addNode(&head, 8);
    addNode(&head, 9);
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 1);

    cout << "The doubly linked list before rotation " << endl;
    printList(head);

    int N = 3;
    // Call the function to rotate doubly linked list by N nodes
    head = rotate(head, N);

    cout << endl
         << "The doubly linked list after rotation " << endl;
    printList(head);
}