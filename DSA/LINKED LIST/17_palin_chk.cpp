#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Check if Linked List is Palindrome

// Given a singly linked list of size N of integers. The task is to check
// if the given linked list is palindrome or not.

// Example 1:

// Input:
// N = 3
// value[] = {1,2,1}
// Output: 1
// Explanation: The given linked list is
// 1 2 1 , which is a palindrome and
// Hence, the output is 1.
// Example 2:

// Input:
// N = 4
// value[] = {1,2,3,4}
// Output: 0
// Explanation: The given linked list
// is 1 2 3 4 , which is not a palindrome
// and Hence, the output is 0.
// Your Task:
// The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

// Expected Time Complexity: O(N)
// Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

// Constraints:
// 1 <= N <= 105

// sol is -->
//  find the mid , from to tail revese the linked
//  the travese the rev->data and cur->data
class Solution
{
public:
    // Function to reverse a linked list
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        // Move slow and fast pointers to find the middle of the linked list
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        Node *reversedSecondHalf = reverse(slow->next);

        // Compare the first and reversed second halves
        Node *curr = head;
        while (reversedSecondHalf != nullptr)
        {
            if (curr->data != reversedSecondHalf->data)
                return false;

            curr = curr->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        return true;
    }
};

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Solution solution;
    if (solution.isPalindrome(head))
        std::cout << "The linked list is a palindrome.\n";
    else
        std::cout << "The linked list is not a palindrome.\n";

    // Clean up the allocated memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
