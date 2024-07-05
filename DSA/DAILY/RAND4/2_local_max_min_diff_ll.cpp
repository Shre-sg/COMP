#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Definition of ListNode
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Your Solution class
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> criticalPoints;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int position = 0;

        // Find critical points
        while (curr != nullptr && curr->next != nullptr)
        {
            if (prev != nullptr && curr->next != nullptr)
            {
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val))
                {
                    criticalPoints.push_back(position);
                }
            }
            prev = curr;
            curr = curr->next;
            position++;
        }

        // If less than 2 critical points found, return {-1, -1}
        if (criticalPoints.size() < 2)
        {
            return {-1, -1};
        }

        // Calculate min and max distances between critical points
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++)
        {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    // Output the result
    cout << "Minimum distance: " << result[0] << ", Maximum distance: " << result[1] << endl;

    // Clean up allocated memory
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
