#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

// Segregate even and odd nodes in a Link List

// Given a link list of size N, modify the list such that all the even numbers appear before all the
// odd numbers in the modified list. The order of appearance of numbers within each segregation
// should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Example 1:

// Input:
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers
// so they appear first and 17,15,9 are odd
// numbers that appear later.

// Example 2:

// Input:
// N = 4
// Link List:
// 1 -> 3 -> 5 -> 7

// Output: 1 3 5 7

// Explaination: There is no even number.
// So no need for modification.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list. Don't create a new linked list, instead rearrange the provided one.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Each element of the list ≤ 105

class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *evenStart = nullptr, *evenEnd = nullptr;
        Node *oddStart = nullptr, *oddEnd = nullptr;

        Node *current = head;

        while (current != nullptr)
        {
            int val = current->data;

            if (val % 2 == 0)
            {
                if (evenStart == nullptr)
                {
                    evenStart = current;
                    evenEnd = evenStart;
                }
                else
                {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            }
            else
            {
                if (oddStart == nullptr)
                {
                    oddStart = current;
                    oddEnd = oddStart;
                }
                else
                {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }

            current = current->next;
        }

        if (evenStart == nullptr || oddStart == nullptr)
            return head;

        evenEnd->next = oddStart;
        oddEnd->next = nullptr;

        return evenStart;
    }
};

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a sample linked list
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(6);

    // Instantiating Solution class
    Solution sol;

    // Calling divide method and printing the modified linked list
    cout << "Original List: ";
    printList(head);
    Node *modifiedHead = sol.divide(7, head);
    cout << "Modified List: ";
    printList(modifiedHead);

    // Freeing memory
    while (modifiedHead != nullptr)
    {
        Node *temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}
