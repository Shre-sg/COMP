#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to print a circular linked list
void printCircularList(Node *head)
{
    if (!head)
    {
        return;
    }

    Node *current = head;
    do
    {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

// Split a Circular Linked List into two halves

// Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

// Example 1:

// Input:
// Circular LinkedList: 1->5->7
// Output:
// 1 5
// 7

// Example 2:

// Input:
// Circular LinkedList: 2->6->1->5
// Output:
// 2 6
// 1 5

// Your Task:
// Your task is to complete the given function splitList(), which takes 3 input parameters: The address of the head of the linked list, addresses of the head of the first and second halved resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.

// Expected Time Complexity: O(N)
// Expected Auxilliary Space: O(1)

// Constraints:
// 2 <= N <= 100

void splitList(Node *head, Node **firstHalf, Node **secondHalf)
{
    if (head == nullptr)
    {
        *firstHalf = nullptr;
        *secondHalf = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    // Move fast pointer two steps and slow pointer one step
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the circular list at the middle
    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = head; // Closing the first half as a circular list

    // Move to the end of the second half to close the circular list
    Node *temp = *secondHalf;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = *secondHalf;
}

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head; // Creating a circular linked list

    std::cout << "Original Circular List: ";
    printCircularList(head);

    Node *firstHalf = nullptr;
    Node *secondHalf = nullptr;

    splitList(head, &firstHalf, &secondHalf);

    std::cout << "First Half: ";
    printCircularList(firstHalf);

    std::cout << "Second Half: ";
    printCircularList(secondHalf);

    return 0;
}
