#include <iostream>
#include <unordered_map>

using namespace std;

// Definition of the Node class
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Count Triplets

// Given a sorted linked list of distinct nodes (no two nodes have the same data)
// and an integer X. Count distinct triplets in the list that sum up to given integer X.
// Note: The Linked List is sorted in decending order.

// Example 1:

// Input: LinkedList: 9->8->6->5->4->2->1,  X = 17
// Output: 2
// Explanation: Distinct triplets are (2, 6, 9)
// and (4, 5, 8) which have sum equal to X i.e 17.

// Example 2:

// Input: LinkedList: 9->8->6->5->4->2->1, X = 15
// Output: 5
// Explanation: (1, 5, 9), (1, 6, 8), (2, 4, 9),
// (2, 5, 8), (4, 5, 6) are the distinct triplets
// Your Task:
// You don't need to read input or print anything. Complete the function countTriplets() which takes a head reference and X as input parameters and returns the triplet count

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// IF IT IS UNSORTED THIS WORKS TOO
//  int countTriplets(struct Node* head, int x)
//  {
//      // code here.
//      vector<int> k;
//      while(head != NULL){
//          k.push_back(head->data);
//          head = head -> next;
//      }
//      sort(k.begin() , k.end());
//      int count = 0;
//      for(int i =k.size() - 1; i>= 2; i--) {
//          int a = 0 ;
//          int b = i - 1;
//          while(a < b) {
//              int sum = k[a] + k[b] + k[i];
//              if(sum == x) {
//                  count++;
//                  a++;
//                  b--;
//              }
//              else if(sum > x) {
//                  b--;
//              }
//              else{
//                  a++;
//              }
//          }
//      }
//      return count;

// }

int countTriplets(struct Node *head, int x)
{
    unordered_map<int, int> m;
    Node *curr = head;
    int res = 0;

    if (curr == NULL or curr->next == NULL or curr->next->next == NULL)
    {
        return 0;
    }

    while (curr->next != NULL)
    {
        Node *temp = curr->next;

        while (temp != NULL)
        {
            if (m.find(x - curr->data - temp->data) != m.end())
            {
                res++;
            }
            temp = temp->next;
        }

        m[curr->data]++;
        curr = curr->next;
    }
    return res;
}

// Example usage
int main()
{
    // Creating a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int x = 6;

    // Calling the countTriplets function
    int result = countTriplets(head, x);

    // Displaying the result
    cout << "Number of triplets with sum " << x << ": " << result << endl;

    // Clean up memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
