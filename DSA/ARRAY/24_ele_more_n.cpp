#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

// Follow up: Could you solve the problem in linear time and in O(1) space?

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        vector <int> ans; //to hold results
        for(int i=0; i<nums.size();i++){
            map[nums[i]]++;
        }
        int key=nums.size()/3;

        for(auto it : map){   //its iterator
            if(it.second>key)   //checking if more add it to the new vector
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main() {
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // Input the elements of the array
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // Create an object of Solution class
    Solution sol;
    // Call the majorityElement method and store the result in a vector
    vector<int> result = sol.majorityElement(nums);
    // Print the result
    cout << "The elements that appear more than n/3 times are: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
