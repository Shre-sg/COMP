#include <iostream>

// Define the Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Given two singly linked lists of size N and M, write a program to get the point where two
// linked lists intersect each other.

// Example 1:

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// Output: 15
// Explanation:
// Y ShapedLinked List
// Example 2:

// Input:
// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// Explanation:

// 4              5
// |              |
// 1              6
//  \             /
//   8   -----  1
//    |
//    4
//    |
//   5
//   |
//   NULL
// Your Task:
// You don't need to read input or print anything. The task is to complete the function intersectPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
// Challenge : Try to solve the problem without using any extra space.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)

// Constraints:
// Length of Both linkedList before intersection(if any) is greater than 0.
// 2 ≤ N + M ≤ 2*105
// -1000 ≤ value ≤ 1000

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
