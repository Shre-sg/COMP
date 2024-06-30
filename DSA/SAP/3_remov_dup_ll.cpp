#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 82. Remove Duplicates from Sorted List II

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *dummy = new ListNode(-1);
        ListNode *h = dummy;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                {
                    head = head->next;
                }
            }
            else
            {
                h->next = head;
                h = h->next;
            }
            head = head->next;
        }
        h->next = nullptr;
        return dummy->next;
    }
};

// using recursion
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *next = head->next;

        if (next->val == head->val)
        {
            while (next && next->val == head->val)
                next = next->next;
            return deleteDuplicates(next);
        }
        else
        {
            head->next = deleteDuplicates(next);
            return head;
        }
    }
};

//
//
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a sample linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode *result = solution.deleteDuplicates(head);

    std::cout << "Result: ";
    printList(result);

    return 0;
}
