#include <iostream>
using namespace std;



// Stickler the thief wants to loot money from a society having n houses in a single line.
// He is a weird person and follows a certain rule when looting the houses. According to the 
//rule, he will never loot two consecutive houses. At the same time, he wants to maximize the 
//amount he loots. The thief knows which house has what amount of money but is unable to come
/// up with an optimal looting strategy. He asks for your help to find the maximum money he 
//can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

// Example 1:

// Input:
// n = 5
// a[] = {6,5,5,7,4}
// Output: 
// 15
// Explanation: 
// Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
// Example 2:

// Input:
// n = 3
// a[] = {1,5,3}
// Output: 
// 5
// Explanation: 
// Loot only 2nd house and get maximum amount of 5.
// Your Task:
// Complete the functionFindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules.

// Expected Time Complexity:O(N).
// Expected Space Complexity:O(1).

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ a[i] ≤ 104






//Your class Solution
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int s1=0,s2=0;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1=max(s1+arr[i],s2);
            }
            else{
                s2=max(s2+arr[i],s1);
            }
        }
        if(s1>s2){
            return s1;
        }
        else{
            return s2;
        }
    }
};

//Main function
int main()
{
    //Creating an object of class Solution
    Solution obj;
    
    //Taking input for the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    //Declaring an array of size n
    int arr[n];
    
    //Taking input for the elements of the array
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    //Calling the FindMaxSum function and printing the result
    int result = obj.FindMaxSum(arr, n);
    cout << "The maximum money the thief can get is: " << result << endl;
    
    return 0;
}
