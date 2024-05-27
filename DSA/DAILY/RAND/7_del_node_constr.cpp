#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    ListNode *rev(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode *removeNodes(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head = rev(head);
        ListNode *cur = head;
        int mx = INT16_MIN; // Initialize mx with the minimum possible integer value

        while (cur != NULL)
        {
            if (cur->val >= mx)
            {
                mx = cur->val;
            }
            if (cur->next != NULL && cur->next->val < mx)
            { // Check if cur->next is not NULL
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return rev(head);
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    cout << "Original List: ";
    printList(head);

    ListNode *modifiedHead = sol.removeNodes(head);

    cout << "Modified List: ";
    printList(modifiedHead);

    return 0;
}
