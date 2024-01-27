#include <iostream>

// Define the Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// https://youtu.be/X_kwcctaQ4M?si=7Np6pDOHPETgiglZ
//  Find the first node of loop in linked list

// Given a singly linked list of N nodes. Find the first node of
// the loop if the linked list has a loop. If a loop is present return the node
// data of the first node of the loop else return -1.

// Example 1:

// Input:

// Output: 3
// Explanation:
// We can see that there exists a loop
// in the given linked list and the first
// node of the loop is 3.

// Example 2:

// Input:

// Output: -1
// Explanation: No loop exists in the above
// linked list.So the output is -1.

// Your Task:
// The task is to complete the function findFirstNode() which contains reference to the head as only argument. This function should return the value of the first node of the loop if the linked list contains a loop, else return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Data on Node <= 106
// 0 <= pos <= N

class Solution
{
public:
    // Function to find the first node if the linked list has a loop.
    int findFirstNode(Node *head)
    {
        // your code here
        if (head == nullptr)
        {
            return -1;
        }

        Node *fast = head;
        Node *slow = head;

        // Step 1: Check if slow and fast meet
        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if (fast == slow)
            {
                slow = head;
                break;
            }
        }

        // No loop found
        if (fast == nullptr || fast->next == nullptr)
        {
            return -1;
        }

        // Step 2: Move slow and fast one step at a time until they meet again
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Return the value of the node where slow and fast meet (start of the loop)
        return slow->data;
    }
};

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution solution;
    int result = solution.findFirstNode(head);

    if (result != -1)
    {
        std::cout << "The first node of the loop is: " << result << std::endl;
    }
    else
    {
        std::cout << "No loop found in the linked list." << std::endl;
    }

    // Don't forget to free the allocated memory
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
