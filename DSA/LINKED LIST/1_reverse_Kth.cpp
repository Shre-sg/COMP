#include <iostream>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node *&head, int data)
{
    if (head == nullptr)
    {
        head = createNode(data);
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Reverse a Linked List in groups of given size
// MediumAccuracy: 57.08%Submissions: 192K+Points: 4
// Fast-track your resumes to top companies via this Free Hiring Challenge!

// banner
// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

// Example 1:

// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5
// Explanation:
// The first 4 elements 1,2,2,4 are reversed first
// and then the next 4 elements 5,6,7,8. Hence, the
// resultant linked list is 4->2->2->1->8->7->6->5.
// Example 2:

// Input:
// LinkedList: 1->2->3->4->5
// K = 3
// Output: 3 2 1 5 4
// Explanation:
// The first 3 elements are 1,2,3 are reversed
// first and then elements 4,5 are reversed.Hence,
// the resultant linked list is 3->2->1->5->4.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= k <= N

// Function to reverse k nodes at a time
Node *reverseIt(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr)
    {
        head->next = reverseIt(next, k);
    }

    return prev;
}

int main()
{
    Node *head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);

    std::cout << "Original linked list: ";
    printList(head);

    int k = 3; // Reverse every 3 nodes
    head = reverseIt(head, k);

    std::cout << "Reversed linked list (k = " << k << "): ";
    printList(head);

    return 0;
}
