#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:
             //Q        //ans
 //[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

//IMPORTANT algo we use
//STEP 1:
// Find the break-point--->
// i: Break-point means the first index i from the back of the given array-<
//          arr[i] < arr[i+1] strating from n-1 of array
// For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
// To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
// 
//STEP 2:
//If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
// So, in this case, we will reverse the whole array and will return it as our answer.
// 
//STEP 3:
//If a break-point exists:
// Find the smallest number than breakpoint (arr[i]) from right side of array n-1;
//then swap those two ele ie breakpoint and smallest ele 

//STEP 4: IMPOTANT
// Reverse the entire right half ie swapped breakpoint ; return the array.



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpt = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                breakpt = i;
                break;
            }
        }

        if(breakpt == -1){ ///no breakpoint reverse whole and return
            reverse(nums.begin(), nums.end());
            return;
        }

        int leastGreater = -1;
        //int MiniGreater = INT_MAX;
      
        for(int i = nums.size()-1; i > breakpt; i--){
            if(nums[i] > nums[breakpt]){
                swap(nums[breakpt], nums[i]);  //swapppint breakpoint and the the smallest num
                break;
            }
        }

        reverse(nums.begin()+breakpt+1, nums.end()); ///reversing the right side after breakpoint
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    sol.nextPermutation(nums);
    cout << "Next permutation: ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
