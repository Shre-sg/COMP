#include <iostream>

// Define the Node structure
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

// Example 1:

// Input:
// N = 5
// value[]  = {3,5,2,4,1}
// Output: 1 2 3 4 5
// Explanation: After sorting the given
// linked list, the resultant matrix
// will be 1->2->3->4->5.
// Example 2:

// Input:
// N = 3
// value[]  = {9,15,0}
// Output: 0 9 15
// Explanation: After sorting the given
// linked list , resultant will be
// 0->9->15.
// Your Task:
// For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
// For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

// Expected Time Complexity: O(N*Log(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 10

// Define the Solution class
class Solution
{
    Node *merge(Node *left, Node *right)
    {
        Node *ans = new Node(-1);
        Node *temp = ans;

        if (left == NULL)
        {
            return right;
        }

        if (right == NULL)
        {
            return left;
        }

        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // break into 2 halves
        Node *mid = getMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;

        // sort both left and right
        left = mergeSort(left);
        right = mergeSort(right);

        // merge both ans return the ans
        Node *result = merge(left, right);
        return result;
    }
};

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

int main()
{
    // Creating a linked list
    Node *head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    std::cout << "Original linked list: ";
    printList(head);

    // Creating an instance of the Solution class
    Solution solution;

    // Sorting the linked list using merge sort
    head = solution.mergeSort(head);

    std::cout << "Sorted linked list: ";
    printList(head);

    // Cleaning up the memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
