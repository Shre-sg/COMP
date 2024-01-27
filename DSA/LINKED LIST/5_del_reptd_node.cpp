#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

// Remove duplicate element from sorted Linked List

// Given a singly linked list consisting of N nodes. The task is to remove duplicates
//(nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.

// Example 1:

// Input:
// LinkedList: 2->2->4->5
// Output: 2 4 5
// Explanation: In the given linked list
// 2 ->2 -> 4-> 5, only 2 occurs more
// than 1 time. So we need to remove it once.
// Example 2:

// Input:
// LinkedList: 2->2->2->2->2
// Output: 2
// Explanation: In the given linked list
// 2 ->2 ->2 ->2 ->2, 2 is the only element
// and is repeated 5 times. So we need to remove
// any four 2.
// Your Task:
// The task is to complete the function removeDuplicates() which takes the head of input linked list as input. The function should remove the duplicates from linked list and return the head of the linkedlist.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= Number of nodes <= 105

Node *removeDuplicates(Node *head)
{

    // easy way to solve the problem
    //   Node *removeDuplicates(Node *head)
    //  {
    //   // your code goes here
    //   if(head==NULL )
    //        return NULL;
    //    Node *curr=head;
    //    while(curr->next!=NULL){
    //        if(curr->data==curr->next->data){
    //            Node *q=curr->next;
    //            curr->next=q->next;
    //            delete q;
    //        }else curr=curr->next;
    //    }
    //    return head;
    //  }

    unordered_set<int> set; // Use set to store the data of nodes
    Node *cur = head;
    Node *prev = NULL;

    while (cur != NULL)
    {
        if (set.find(cur->data) != set.end())
        {
            prev->next = cur->next;
            delete cur; // free memory of duplicate node
        }
        else
        {
            set.insert(cur->data);
            prev = cur;
        }
        cur = cur->next;
    }

    return head;
}

int main()
{
    // Example usage
    Node *head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    cout << "Original list: ";
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free memory
    current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
