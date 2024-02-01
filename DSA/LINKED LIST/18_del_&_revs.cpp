#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};
// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}
// Deletion and Reverse in Linked List

// Given a Circular Linked List of size N. The task is to delete the given node in the
// circular linked list and then print the reverse of the circular linked list.

// Example 1:

// Input:
// 5
// 2 5 7 8 10
// 8

// Output:
// 10 7 5 2
// Explanation:
// After deleting 8 from the given circular linked
// list, it has elements as 2, 5, 7, 10. Now,
// reversing this list will result in 10, 7, 5, 2.

// Example 2:

// Input:
// 4
// 1 7 8 10
// 8

// Output:
// 10 7 1

// Explanation:
// After deleting 8 from the given circular linked
// list, it has elements as 1, 7,10. Now, reversing
// this list will result in 10, 7, 1.

// Your Task:
// You don't need to read, input, or print anything. Your task is to complete the function deleteNode( ), which takes Node head, and integer key as input parameters, and delete the node with data key. Also Complete function reverse() which reverses the linked list.

// Constraints:
// 1 <= T <= 100
// 2 <= n <= 100
// 1 <= data <= 100

void deleteNode(Node **head, int key)
{
    Node *temp = *head;
    Node *prev = nullptr;
    Node *curr = temp;

    // If the node to be deleted is the head
    if (curr != nullptr && curr->data == key)
    {
        *head = curr->next;
        delete curr;
        return;
    }

    // Find the node with the given key
    while (curr != nullptr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    // If the key is not found
    if (curr == nullptr)
    {
        std::cout << "Key not found in the linked list.\n";
        return;
    }

    // If the node to be deleted is not the head
    prev->next = curr->next;
    delete curr;
}

// Function to reverse the linked list
void reverse(Node **head_ref)
{
    Node *temp = *head_ref;
    Node *curr = temp->next;
    Node *prev = temp;
    Node *forward = nullptr;

    while (curr != temp)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    curr->next = prev;
    *head_ref = prev;
}

int main()
{
    // Example usage
    Node *head = new Node(10);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);

    std::cout << "Original Linked List: ";
    printList(head);

    // Delete node with key 8
    deleteNode(&head, 8);
    std::cout << "Linked List after deleting node with key 8: ";
    printList(head);

    // Reverse the linked list
    reverse(&head);
    std::cout << "Reversed Linked List: ";
    printList(head);

    // Clean up the allocated memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
