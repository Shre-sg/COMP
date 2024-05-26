// 552. Student Attendance Record II

// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attend    ance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:

// Input: n = 1
// Output: 3
// Example 3:

// Input: n = 10101
// Output: 183236316

// Constraints:

// 1 <= n <= 105

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int countValidRecords(int p_day, int ab_day, int con_late, vector<vector<vector<int>>> &memo)
    {
        if (ab_day > 1)
            return 0; // Too many absents

        if (con_late > 2)
            return 0; // Too many consecutive lates

        if (p_day == 0)
            return 1; // No more days to consider, valid record

        if (memo[p_day][ab_day][con_late] != -1)
            return memo[p_day][ab_day][con_late];

        // Add 'P' (present) -> reset consecutive lates to 0
        int count = countValidRecords(p_day - 1, ab_day, 0, memo);
        count %= MOD;

        // Add 'A' (absent) -> decrease absents remaining by 1, reset consecutive lates to 0
        count += countValidRecords(p_day - 1, ab_day + 1, 0, memo);
        count %= MOD;

        // Add 'L' (late) -> increase consecutive lates by 1
        count += countValidRecords(p_day - 1, ab_day, con_late + 1, memo);
        count %= MOD;

        memo[p_day][ab_day][con_late] = count;
        return count;
    }

    int checkRecord(int n)
    {
        // memo[daysRemaining][absents][consecutiveLates]
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2 + 1, vector<int>(3, -1)));
        return countValidRecords(n, 0, 0, memo);
    }
};

int main()
{
    Solution solution;
    int n = 5; // Example: check valid records for 5 days
    int result = solution.checkRecord(n);
    cout << "Number of valid attendance records for " << n << " days: " << result << endl;
    return 0;
}
