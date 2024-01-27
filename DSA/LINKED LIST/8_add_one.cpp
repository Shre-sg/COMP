#include <iostream>

// Definition for singly-linked list
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    Node *addOne(Node *head);

private:
    Node *reverseList(Node *head);
};

// Add 1 to a number represented as linked list
// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457
// Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457.
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124
// Your Task:
// Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
// Note: The head represents the left-most digit of the number.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 1021

Node *Solution::reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

Node *Solution::addOne(Node *head)
{
    // Reverse the linked list
    Node *rev = reverseList(head);

    Node *temp = rev;
    Node *prev = nullptr;
    int carry = 1; // INIT TO 1;

    while (temp != nullptr)
    {
        // OP NEEDED

        // Original list: 9 9 9
        // List after adding one: 1 0 0 0
        temp->data += carry;
        carry = temp->data / 10;
        temp->data %= 10;
        prev = temp;
        temp = temp->next;
    }

    // If there's a carry after the last node, create a new node
    if (carry > 0)
    {
        Node *newNode = new Node(carry);
        prev->next = newNode;
    }

    // Reverse the list again to get the final result
    head = reverseList(rev);

    return head;
}

// Utility function to print the linked list
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
    // Create a sample linked list
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    std::cout << "Original list: ";
    printList(head);

    // Add one to the linked list
    Solution solution;
    head = solution.addOne(head);

    std::cout << "List after adding one: ";
    printList(head);

    // Free memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
