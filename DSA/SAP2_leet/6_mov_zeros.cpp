#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != 0)
            {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    cout << "Test case 1: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1};
    solution.moveZeroes(nums2);
    cout << "Test case 2: ";
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> nums3 = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    solution.moveZeroes(nums3);
    cout << "Test case 3: ";
    for (int num : nums3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
