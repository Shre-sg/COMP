#include <iostream>

// Define the Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Add two numbers represented by linked lists

// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// Example 1:

// Input:
// N = 2
// valueN[] = {4,5}
// M = 3
// valueM[] = {3,4,5}
// Output: 3 9 0
// Explanation: For the given two linked
// list (4 5) and (3 4 5), after adding
// the two linked list resultant linked
// list will be (3 9 0).
// Example 2:

// Input:
// N = 2
// valueN[] = {6,3}
// M = 1
// valueM[] = {7}
// Output: 7 0
// Explanation: For the given two linked
// list (6 3) and (7), after adding the
// two linked list resultant linked list
// will be (7 0).
// Your Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

// Constraints:
// 1 <= N, M <= 5000

// Define the Solution class
class Solution
{
public:
    // Function to reverse a linked list
    Node *reverse(Node *head)
    {
        Node *prevNode = nullptr;
        Node *currNode = head;
        Node *nextNode = nullptr;

        while (currNode)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    // reverse twon LL add the two first ele of ll then note down carray

    // Function to add two numbers represented by linked list.
    Node *addTwoLists(Node *first, Node *second)
    {
        Node *head1 = reverse(first);
        Node *head2 = reverse(second);

        Node *head = nullptr;
        Node *curr = nullptr;

        int carry = 0;
        int sum = 0;

        while (head1 || head2 || carry)
        {
            sum = (head1 ? head1->data : 0) + (head2 ? head2->data : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;

            curr = new Node(sum);
            curr->next = head;
            head = curr;

            if (head1)
                head1 = head1->next;
            if (head2)
                head2 = head2->next;
        }
        return head;
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
    // Create linked list 1: 123 (1->2->3)
    Node *first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);

    // Create linked list 2: 456 (4->5->6)
    Node *second = new Node(4);
    second->next = new Node(5);
    second->next->next = new Node(6);

    // Create an instance of the Solution class
    Solution solution;

    // Add two linked lists
    Node *result = solution.addTwoLists(first, second);

    // Print the result
    std::cout << "Result: ";
    printList(result);

    // Clean up memory
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
