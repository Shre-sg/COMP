// 1482. Minimum Number of Days to Make m Bouquets
// Medium
// Topics
// Companies
// Hint
// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:

// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

// Constraints:

// bloomDay.length == n
// 1 <= n <= 105
// 1 <= bloomDay[i] <= 109
// 1 <= m <= 106
// 1 <= k <= n

// Algorithm / Intuition
// Optimal Approach(Using Binary Search):
// We are going to use the Binary Search algorithm to optimize the approach.

// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

// Now, we are not given any sorted array on which we can apply binary search. But, if we observe closely, we can notice that our answer space i.e. [mini(arr[]), max(arr[])] is sorted. So, we will apply binary search on the answer space.

// Algorithm:
// If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
// Next, we will find the maximum element i.e. max(arr[]), and the minimum element i.e. min(arr[]) in the array.
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to min(arr[]) and the high will point to max(arr[]).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
// mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Eliminate the halves based on the value returned by possible():
// We will pass the potential answer, represented by the variable 'mid' (which corresponds to a specific day), to the 'possible()' function.
// If possible() returns true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
// The steps from 3-5 will be inside a loop and the loop will continue until low crosses high.

// Note: Please make sure to refer to the video and try out some test cases of your own to understand, how the pointer ‘low’ will be always pointing to the answer in this case. This is also the reason we have not used any extra variable here to store the answer.

// Dry-run: Please refer to the video for the dry-run.

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n)
        return -1; // impossible case.
    // find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    // apply binary search:
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}

// brute force

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n)
        return -1; // impossible case.
    // find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}

//leetcode
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
};