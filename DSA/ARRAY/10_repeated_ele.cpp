#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

int findDuplicate(vector<int> &nums)
{
    // initialise index vector of size nums with 0
    int index[999];
    int i=0;
    while (i<999)
    {
        index[i]=0;
        i++;
    }
    
    int ind = 0;

    // store the cnt of each value in the cnt vector
    for (int i = 0; i < nums.size(); i++)
    {
        index[nums[i]]++;
    }

    for (int i = 0; i < 999; i++)
    {
        // if cnt[i] > 1
        // this means that element occur more than once in nums
        // we have to return i
        if (index[i] > 1)
        {
            ind = i;
            break;
        }
    }

    return ind;
}

int main()
{
    // uniform initialization
    // vector<int> v2{1, 2, 3, 4, 5};

    // METHOD - 2 (5,1)  5-->size, 1-->initialzer value
    // vector<int> v3(5, 1);
 
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter element " << i+1 << ": ";
        cin >> x;
        nums.push_back(x);
    }

    //   vector<int> nums = {1, 2, 3, 4, 5};  ///printing ele in vector
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "Index: " << i << ", Element: " << nums[i] << endl;
    }
    
    int res=findDuplicate(nums);
    cout<<nums[res];
}

//IMPO using haSH MAP

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int, int> m;
//         int duplicate = 0;
//         for(auto i= 0; i<nums.size(); ++i)
//         ++m[nums[i]];
        
//         for(auto i : m)
//         {
//             if(i.second > 1)
//             {
//                 duplicate = i.first;
//                 break;
//             }
//         }
//         return duplicate;
//     }
// 	// for github repository link go to my profile.
// };