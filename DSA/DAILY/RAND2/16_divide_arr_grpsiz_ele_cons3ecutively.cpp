#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 846. Hand of Straights

// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

// Constraints:

// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length

// Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> mp;
        for (int i = 0; i < hand.size(); i++)
        {
            mp[hand[i]]++;
        }

        for (auto it = mp.begin(); it != mp.end();)
        {
            if (it->second > 0) // if the maps freq is greater add them to group
            {
                for (int i = 0; i < groupSize; i++) // now i am looking for consecutive ele
                {
                    if (mp[it->first + i] > 0) // if consecutive ele is missing ie does satify size of groupsize then return flase
                    {
                        mp[it->first + i]--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                it++; // incetemt the iteer
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int n, groupSize;

    // Read input for the hand vector
    cout << "Enter the number of cards in the hand: ";
    cin >> n;
    vector<int> hand(n);
    cout << "Enter the cards in the hand: ";
    for (int i = 0; i < n; i++)
    {
        cin >> hand[i];
    }

    // Read input for the group size
    cout << "Enter the group size: ";
    cin >> groupSize;

    // Call the function and output the result
    bool result = solution.isNStraightHand(hand, groupSize);
    if (result)
    {
        cout << "The hand can be rearranged into groups of " << groupSize << " consecutive cards." << endl;
    }
    else
    {
        cout << "The hand cannot be rearranged into groups of " << groupSize << " consecutive cards." << endl;
    }

    return 0;
}
