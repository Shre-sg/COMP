#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int val) : data(val), next(NULL) {}
};

// Function to swap data of two nodes
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to print the linked list
void printList(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to push a new node to the linked list
void push(node *&head, int data)
{
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

// Quick Sort on Linked List

// Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

// Input:
// In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
// The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
// There are multiple test cases. For each test case, this method will be called individually.

// Output:
// Set *headRef to head of resultant linked list.

// User Task:
// The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

// Constraints:
// 1<=T<=100
// 1<=N<=200

// Note: If you use "Test" or "Expected Output Button" use below example format

// Example:
// Input:
// 2
// 3
// 1 6 2
// 4
// 1 9 3 8

// Output:
// 1 2 6
// 1 3 8 9

// Explanation:
// Testcase 1: After sorting the nodes, we have 1, 2 and 6.
// Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.

node *partition(node *head, node *tail)
{
    node *curr = head, *prev = head, *pivot = head;

    while (curr != tail->next)
    {
        if (curr->data < pivot->data)
        {
            swap(curr->data, prev->next->data);
            prev = prev->next;
        }
        curr = curr->next;
    }

    swap(pivot->data, prev->data);
    return prev;
}

// Quicksort function for linked list
void quicksort(node *head, node *tail)
{
    if (!head || !tail || (head == tail))
        return;
    node *pivot = partition(head, tail);
    quicksort(head, pivot);
    quicksort(pivot->next, tail);
}

// Wrapper function for quicksort on linked list
void quickSort(struct node **headRef)
{
    node *head = *headRef, *tail = head;

    if (!head || !head->next)
        return;

    while (tail->next)
        tail = tail->next;

    quicksort(head, tail);
}

int main()
{
    // Example usage
    node *head = NULL;

    // Push elements to the linked list
    push(head, 5);
    push(head, 2);
    push(head, 9);
    push(head, 1);
    push(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Sort the linked list using quicksort
    quickSort(&head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
