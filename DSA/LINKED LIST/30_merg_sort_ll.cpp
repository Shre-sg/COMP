#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merge K sorted linked lists

// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after
// merging they will be a single sorted linked list.

// Example 1:

// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.
// Example 2:

// Input:
// K = 3
// value = {{1,3},{4,5,6},{8}}
// Output: 1 3 4 5 6 8
// Explanation:
// The test case has 3 sorted linked
// list of size 2, 3, 1.
// 1st list 1 -> 3
// 2nd list 4 -> 5 -> 6
// 3rd list 8
// The merged list will be
// 1->3->4->5->6->8.
// Your Task:
// The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)
// Note: n is the maximum size of all the k link list

class Solution
{
public:
    // Function to merge K sorted linked lists.
    ListNode *mergeKLists(ListNode *arr[], int K)
    {
        // Creating a min-heap to store the values of all nodes from K linked lists
        priority_queue<int, vector<int>, greater<int>> heap;

        // Inserting all values from K linked lists into the min-heap
        for (int i = 0; i < K; i++)
        {
            ListNode *temp = arr[i];
            while (temp != NULL)
            {
                heap.push(temp->val);
                temp = temp->next;
            }
        }

        // Creating a dummy node to simplify the process of building the merged linked list
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        // Building the merged linked list from the min-heap
        while (!heap.empty())
        {
            curr->next = new ListNode(heap.top());
            heap.pop();
            curr = curr->next;
        }

        // Returning the head of the merged linked list
        return dummy->next;
    }
};

// Function to print a linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    ListNode *arr1[] = {new ListNode(1), new ListNode(4), new ListNode(5)};
    arr1[0]->next = new ListNode(1);
    arr1[0]->next->next = new ListNode(2);
    arr1[1]->next = new ListNode(3);
    arr1[1]->next->next = new ListNode(4);
    arr1[2]->next = new ListNode(6);

    int K = 3;

    Solution sol;
    ListNode *mergedList = sol.mergeKLists(arr1, K);
    cout << "Merged Linked List: ";
    printList(mergedList);

    // Freeing memory
    for (int i = 0; i < K; i++)
    {
        ListNode *temp = arr1[i];
        while (temp != NULL)
        {
            ListNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    return 0;
}
