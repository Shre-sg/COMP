#include <iostream>
#include <vector>
using namespace std;

// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

//IMPORTANT SLIDING WINDO TECQ

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int minL = n+1;   //stores the min val of index required for the targetv sum
        
        while(j < n) {          //move acrooss the whole array
            sum += nums[j];   /// keeps track of the current sum; 

            while(sum >= target) {         //when sum becomes more than the target  
                minL = min(minL, j-i+1);   //update the sum min index 
                sum -= nums[i];         /// we have move left index to right ie we have minu the sum with that
                i++;      //moving left index
            }
            
            j++;    //as sum is less than the taget we move right index to right to add ele
        } 
        return minL == n+1 ? 0 : minL;  //
    }
};

int main() {
    Solution obj;
    // Declare and initialize an integer target and a vector of integers nums
    int target = 7;
    vector<int> nums {2, 3, 1, 2, 4, 3};

    int ans = obj.minSubArrayLen(target, nums);
    cout << ans << endl;

    return 0;
}
