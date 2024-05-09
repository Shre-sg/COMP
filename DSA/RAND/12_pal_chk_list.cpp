#include <iostream>

using namespace std;

// 234. Palindrome Linked List

// Given the head of a singly linked list, return true if it is a
// palindrome
//  or false otherwise.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

// Follow up: Could you do it in O(n) time and O(1) space?

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *nex = head;

        while (nex != NULL)
        {
            nex = nex->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp2 = rev(slow);
        ListNode *temp1 = head;

        while (temp2 != NULL)
        {
            if (temp2->val != temp1->val)
            {
                return false;
            }
            temp2 = temp2->next;
            temp1 = temp1->next;
        }

        return true;
    }
};

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    cout << "Is Palindrome: " << (solution.isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
