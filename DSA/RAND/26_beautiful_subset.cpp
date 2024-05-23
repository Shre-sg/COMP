#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 2597. The Number of Beautiful Subsets

// You are given an array nums of positive integers and a positive integer k.

// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

// Return the number of non-empty beautiful subsets of the array nums.

// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

// Example 1:

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
// Example 2:

// Input: nums = [1], k = 1
// Output: 1
// Explanation: The beautiful subset of the array nums is [1].
// It can be proved that there is only 1 beautiful subset in the array [1].

// Constraints:

// 1 <= nums.length <= 20
// 1 <= nums[i], k <= 1000
class Solution
{
public:
    int ans;
    unordered_map<int, int> rec;

    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        ans = 0;
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            rec[nums[i]]++;
            recursion(i + 1, n, tmp, nums, k);
            rec[nums[i]]--;
        }
        return ans;
    }

    void recursion(int pos, int n, vector<int> &tmp, vector<int> &nums, int k)
    {
        if (pos == n)
        {
            ans++;
            return;
        }
        if (rec[nums[pos] - k] == 0)
        {
            rec[nums[pos]]++;
            recursion(pos + 1, n, tmp, nums, k);
            rec[nums[pos]]--;
        }
        recursion(pos + 1, n, tmp, nums, k);
    }
};

int main()
{
    Solution sol;
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.beautifulSubsets(nums, k);
    cout << "Number of beautiful subsets: " << result << endl;

    return 0;
}
