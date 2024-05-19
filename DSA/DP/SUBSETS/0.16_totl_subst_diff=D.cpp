// Part 2: Count Partitions with Given Difference

// Problem Link: Partitions with Given Difference

// Problem Description:

// We are given an array ‘ARR’ with N positive integers and an integer D. We need to count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.

// Disclaimer: Don't jump directly to the solution, try it out yourself first.
// Pre-req: Count Subsets with Sum K

// Solution :
// This question is a slight modification of the problem discussed in Count Subsets with Sum K.
// We have the following two conditions given to us.
// S1 + S2 = D   – (i)
// S1 >= S2     – (ii)
//  If we calculate the total sum of elements of the array (say totSum), we can say that,
// S1 = totSum - S2      – (iii)
// Now solving for equations (i) and (iii), we can say that 
// S2 = (totSum - D)/2    – (iv)
// Therefore the question “Count Partitions with a difference D” is modified to “Count Number of subsets with sum (totSum - D)/2 ”. This is exactly what we had discussed in the article  Count Subsets with Sum K.

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid subset
    if (target == 0)
        return 1;

    // Base case: If we have considered all elements and the target is still not 0, return 0
    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken + taken;
}


int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2; //logic
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}

int main() {

  vector<int> arr = {5,2,6,4};
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(d,arr);
}