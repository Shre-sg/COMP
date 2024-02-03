#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Assuming there is a Node class defined somewhere
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Find pairs with given sum in doubly linked list

// Given a sorted doubly linked list of positive distinct elements,
// the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

// Example 1:

// Input:
// 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
// target = 7
// Output: (1, 6), (2,5)
// Explanation: We can see that there are two pairs
// (1, 6) and (2,5) with sum 7.

// Example 2:

// Input:
// 1 <-> 5 <-> 6
// target = 6
// Output: (1,5)
// Explanation: We can see that there is one pairs  (1, 5) with sum 6.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// Constraints:
// 1 <= N <= 105
// 1 <= target <= 105

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *curr = head;
        vector<pair<int, int>> pairs;
        unordered_map<int, int> mp;

        while (curr)
        {
            if (mp.find(target - (curr->data)) != mp.end())
                pairs.push_back({target - (curr->data), curr->data});

            mp[curr->data]++;
            curr = curr->next;
        }

        sort(pairs.begin(), pairs.end());
        return pairs;
    }
};

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution solution;
    vector<pair<int, int>> result = solution.findPairsWithGivenSum(head, 5);

    // Displaying the result
    for (const auto &pair : result)
    {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }

    // Clean up memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
