#include <iostream>
#include <vector>
#include <queue>

// 2073. Time Needed to Buy Tickets

// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the
// line and the (n - 1)th person is at the back of the line.
// You are given a 0-indexed integer array tickets of length n where the number of tickets
// that the ith person would like to buy is tickets[i].
// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a
// time and has to go back to the end of the line (which happens instantaneously) in order to
// buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.
// Return the time taken for the person at position k (0-indexed) to finish buying tickets.

// Example 1:

// Input: tickets = [2,3,2], k = 2
// Output: 6
// Explanation:
// - In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
// - In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
// The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
// Example 2:

// Input: tickets = [5,1,1,1], k = 0
// Output: 8
// Explanation:
// - In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
// - In the next 4 passes, only the person in position 0 is buying tickets.
// The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.

using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<pair<int, int>> q;
        int n = tickets.size();

        for (int i = 0; i < n; i++)
        {
            q.push({tickets[i], i});
        }

        int cnt = 0;
        while (!q.empty())
        {
            int element = q.front().first;
            int index = q.front().second;
            q.pop();

            if (element - 1 > 0)
            {
                q.push({element - 1, index});
                cnt++;
            }
            else
            {
                cnt++;
            }

            if (element - 1 == 0 && index == k)
            {
                return cnt;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solution;

    // Example usage
    vector<int> tickets = {2, 3, 4, 5}; // Example ticket values
    int k = 2;                          // Index of the ticket to buy
    cout << "Time required to buy ticket at index " << k << ": " << solution.timeRequiredToBuy(tickets, k) << endl;

    return 0;
}
