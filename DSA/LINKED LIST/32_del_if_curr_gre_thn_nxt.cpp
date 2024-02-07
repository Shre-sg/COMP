#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *frw = NULL;
        while (curr != NULL)
        {
            frw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frw;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        // Reverse the linked list
        // we are doing this becaue if the first need to be delted it is impossible to do that.
        Node *reversed_head = reverse(head);

        Node *prev = reversed_head;
        Node *curr = reversed_head->next;

        while (curr != NULL)
        {
            if (curr->data < prev->data)
            {
                // Delete the current node
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        // Reverse the modified linked list again to get the original order
        Node *result = reverse(reversed_head);
        return result;
    }
};

// Function to print a linked list
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
    // Creating a sample linked list: 1 -> 3 -> 2 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create an instance of Solution class
    Solution sol;

    // Compute the modified linked list
    Node *result = sol.compute(head);

    // Print the modified linked list
    cout << "Modified Linked List: ";
    printList(result);

    // Freeing memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
