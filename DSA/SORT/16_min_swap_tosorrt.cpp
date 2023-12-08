#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// Given an array of n distinct elements. Find the minimum number of swaps required to 
//sort the array in strictly increasing order.


// Example 1:

// Input:
// nums = {2, 8, 5, 4}
// Output:
// 1
// Explanation:
// swap 8 with 4.
// Example 2:

// Input:
// nums = {10, 19, 6, 3, 5}
// Output:
// 2
// Explanation:
// swap 10 with 3 and swap 19 with 5.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array.
// If the array is already sorted, return 0. 


// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)



//Your class Solution definition here
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
{
  int swaps=0;
  
  vector<pair<int,int>> v;              //to store the ele in vector pairs we can sort later
  for(int i=0;i<nums.size();i++)
  {
      v.push_back({nums[i],i});       
  }
  
  sort(v.begin(),v.end());          //sorting the vetor
  
  for(int i=0;i<nums.size();i++)        
  {
      pair<int,int>p = v[i];        //checking the algo one by one
      
      int value=p.first;
      int index=p.second;
      
      if(i!=index)                  
      {
          swaps++;
          swap(v[i],v[index]);
          i--;
      }
  }
  
  return swaps;
}
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 3, 2, 1}; //You can change the input array here
    int ans = sol.minSwaps(nums);
    cout << "The minimum number of swaps required to sort the array is " << ans << endl;
    return 0;
}
