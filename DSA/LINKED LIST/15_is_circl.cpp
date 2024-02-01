#include <iostream>

// Definition of Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};
// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
        if (current == head)
        {
            break; // To handle circular linked list
        }
    }
    std::cout << std::endl;
}

// Check If Circular Linked List

// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

// Note: The linked list does not contains any inner loop.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// (the first and last node is connected,
// i.e. 5 --> 1)
// Output: 1
// Example 2:

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 0
// Your Task:
// The task is to complete the function isCircular() which checks if the given linked list is circular or not. It should return true or false accordingly. (the driver code prints 1 if the returned values is true, otherwise 0)

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <=Number of nodes<= 100

bool isCircular(Node *head)
{
    Node *temp = head;

    if (head == nullptr)
    {
        return false;
    }

    while (temp && temp->next != nullptr)
    {
        if (temp->next == head)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Creating a circular linked list

    std::cout << "Linked List: ";
    printList(head);

    bool result = isCircular(head);

    if (result)
    {
        std::cout << "The linked list is circular." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not circular." << std::endl;
    }

    return 0;
}
