// 2816. Double a Number Represented as a Linked List

// You are given the head of a non-empty linked list representing a non-negative integer without
// leading zeroes.

// Return the head of the linked list after doubling it.

// Example 1:

// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:

// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.

// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        // Reverse the linked list
        ListNode *reversedList = reverseList(head);
        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode *current = reversedList, *previous = nullptr;

        // Traverse the reversed linked list
        while (current != nullptr)
        {
            // Calculate the new value for the current node
            int newValue = current->val * 2 + carry;
            // Update the current node's value
            current->val = newValue % 10;
            // Update carry for the next iteration
            carry = newValue / 10;
            // Move to the next node
            previous = current;
            current = current->next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0)
        {
            ListNode *extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode *result = reverseList(reversedList);

        return result;
    }

    // Method to reverse the linked list
    ListNode *reverseList(ListNode *node)
    {
        ListNode *previous = nullptr, *current = node, *nextNode;

        // Traverse the original linked list
        while (current != nullptr)
        {
            // Store the next node
            nextNode = current->next;
            // Reverse the link
            current->next = previous;
            // Move to the next nodes
            previous = current;
            current = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return previous;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> nullptr
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Printing the original linked list
    cout << "Original linked list: ";
    printList(head);

    // Doubling the values of the linked list
    Solution sol;
    ListNode *doubledList = sol.doubleIt(head);

    // Printing the modified linked list
    cout << "Modified linked list: ";
    printList(doubledList);

    return 0;
}
