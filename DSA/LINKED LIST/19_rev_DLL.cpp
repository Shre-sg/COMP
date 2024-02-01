#include <iostream>

// Node structure for a doubly linked list
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Function to print the doubly linked list
void printDLL(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

// Reverse a Doubly Linked List

// Given a doubly linked list of n elements. Your task is to reverse the doubly
// linked list in-place.

// Example 1:

// Input:
// LinkedList: 3 <--> 4 <--> 5
// Output: 5 4 3
// Example 2:

// Input:
// LinkedList: 75 <--> 122 <--> 59 <--> 196
// Output: 196 59 122 75
// Your Task:
// Your task is to complete the given function reverseDLL(), which takes head reference as argument and this function should reverse the elements such that the tail becomes the new head and all pointers are pointing in the right order. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= number of nodes <= 104
// 0 <= value of nodes <= 104

// Solution class
class Solution
{
public:
    // Function to reverse a doubly linked list
    Node *reverseDLL(Node *head)
    {
        Node *tail = nullptr;
        Node *currptr = head;

        while (currptr != nullptr)
        {
            Node *nextptr = currptr->next;
            currptr->next = currptr->prev;
            currptr->prev = nextptr;
            tail = currptr; // Update tail to the current node
            currptr = nextptr;
        }

        // Update head to the tail
        head = tail;

        return head;
    }
};

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    std::cout << "Original Doubly Linked List: ";
    printDLL(head);

    // Create an instance of the Solution class
    Solution solution;

    // Reverse the doubly linked list
    Node *reversedHead = solution.reverseDLL(head);

    std::cout << "Reversed Doubly Linked List: ";
    printDLL(reversedHead);

    // Clean up the allocated memory
    while (reversedHead != nullptr)
    {
        Node *temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
