#include <iostream>

// Define the Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Intersection of two sorted Linked lists

// Given two linked lists sorted in increasing order, create a new linked list
// representing the intersection of the two linked lists. The new linked list should be made
// with without changing the original lists.

// Note: The elements of the linked list are not necessarily distinct.

// Example 1:

// Input:
// LinkedList1 = 1->2->3->4->6
// LinkedList2 = 2->4->6->8
// Output: 2 4 6
// Explanation: For the given two
// linked list, 2, 4 and 6 are the elements
// in the intersection.
// Example 2:

// Input:
// LinkedList1 = 10->20->40->50
// LinkedList2 = 15->40
// Output: 40
// Your Task:
// You don't have to take any input of print anything. Your task is to complete the function findIntersection(), which will take head of both of the linked lists as input and should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(n+m)
// Note: n, m are the size of the respective linked lists.

// Constraints:
// 1 <= size of linked lists <= 5000
// 1 <= Data in linked list nodes <= 104

// Define the Solution class
class Solution
{
public:
    // Function to find the intersection of two linked lists
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        Node *intersection = nullptr;
        Node *tail = nullptr;

        while (ptr1 && ptr2)
        {
            if (ptr1->data == ptr2->data)
            {
                if (intersection == nullptr)
                {
                    Node *newNode = new Node(ptr1->data);
                    intersection = newNode;
                    tail = newNode;
                }
                else
                {
                    Node *newNode = new Node(ptr1->data);
                    tail->next = newNode;
                    tail = newNode;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->data < ptr2->data)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }

        return intersection;
    }
};

// Function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create linked list 1: 1->2->3->4
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    // Create linked list 2: 2->4->6
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    // Create an instance of the Solution class
    Solution solution;

    // Find and print the intersection
    Node *intersection = solution.findIntersection(head1, head2);
    std::cout << "Intersection: ";
    printList(intersection);

    // Clean up memory
    while (head1)
    {
        Node *temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2)
    {
        Node *temp = head2;
        head2 = head2->next;
        delete temp;
    }

    while (intersection)
    {
        Node *temp = intersection;
        intersection = intersection->next;
        delete temp;
    }

    return 0;
}
