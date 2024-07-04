#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 2181. Merge Nodes in Between Zeros

// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Return the head of the modified linked list.

// Example 1:

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.
// Example 2:

// Input: head = [0,1,0,3,0,2,2,0]
// Output: [1,3,4]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 1 = 1.
// - The sum of the nodes marked in red: 3 = 3.
// - The sum of the nodes marked in yellow: 2 + 2 = 4.

// Constraints:

// The number of nodes in the list is in the range [3, 2 * 105].
// 0 <= Node.val <= 1000
// There are no two consecutive nodes with Node.val == 0.
// The beginning and end of the linked list have Node.val == 0.

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;
        ListNode *start = head;
        while (start)
        {
            ListNode *end = start;
            int sum = 0;
            while (end->val != 0)
            {
                sum += end->val;
                end = end->next;
            }
            start->val = sum;
            start->next = end->next;
            start = start->next;
        }
        return head;
    }
};

// Helper function to create a linked list from an array
ListNode *createList(int arr[], int size)
{
    if (size == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; ++i)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Example usage
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode *mergedHead = solution.mergeNodes(head);

    cout << "Merged list: ";
    printList(mergedHead);

    return 0;
}
