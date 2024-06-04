// 3169. Count Days Without Meetings

// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

// Return the count of days when the employee is available for work but no meetings are scheduled.

// Note: The meetings may overlap.

// Example 1:

// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

// Output: 2

// Explanation:

// There is no meeting scheduled on the 4th and 8th days.

// Example 2:

// Input: days = 5, meetings = [[2,4],[1,3]]

// Output: 1

// Explanation:

// There is no meeting scheduled on the 5th day.

// Example 3:

// Input: days = 6, meetings = [[1,6]]

// Output: 0

// Explanation:

// Meetings are scheduled for all working days.

// Constraints:

// 1 <= days <= 109
// 1 <= meetings.length <= 105
// meetings[i].length == 2
// 1 <= meetings[i][0] <= meetings[i][1] <= days

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            int currentStart = intervals[i][0], currentEnd = intervals[i][1];

            if (currentStart > end)
            {
                ans.push_back({start, end});
                start = currentStart;
            }
            end = max(end, currentEnd);
        }
        ans.push_back({start, end});

        return ans;
    }

    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<vector<int>> mergedMeetings = mergeIntervals(meetings);

        int busyDays = 0;
        for (vector<int> d : mergedMeetings)
        {
            int start = d[0], end = d[1];
            busyDays += (end - start + 1);
        }

        return days - busyDays;
    }
};

int main()
{
    Solution solution;
    int totalDays = 10;
    vector<vector<int>> meetings = {{1, 3}, {2, 5}, {7, 9}};

    cout << "The number of free days is: " << solution.countDays(totalDays, meetings) << endl;
    return 0;
}
