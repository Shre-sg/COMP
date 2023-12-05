#include <iostream>
#include <vector>
using namespace std;


// Given a sorted array arr containing n elements with possibly some duplicate, the task is to
// find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.


// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  
// 2 5
// Explanation: 
// First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
// Example 2:

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:  
// 6 6
// Explanation: 
// First and last occurrence of 7 is at index 6.
// Your Task:
// Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1).

//oder of N
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int start=-1, end=-1;
        vector<int> ans;
        int count=0;
        
        for(int i=0; i<n ; i++){
            if(arr[i]==x){
                count++;
                
                if(count == 1)
                    start=i;
                
                end=i;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    Solution obj;
    vector<int> result = obj.find(arr, n, x);
    cout << "Starting index: " << result[0] << endl;
    cout << "Ending index: " << result[1] << endl;
    return 0;
}

// ODER log N

//  ArrayList<Integer> find(int arr[], int n, int x)
//     {
//         ArrayList<Integer> list = new ArrayList<>();
//         int left = 0, right = n-1;
//         list.add(-1);
//         list.add(-1);
             
//         while(left <= right) {
//             if(arr[left] == x && arr[right] == x) {
//                 list.add(0,left);
//                 list.add(1,right);
//                 break;
//             }
//             if(arr[left] != x ) 
//                    left++;
//            
//             if(arr[right] != x ) 
//                    right--;
//          }
//         return list;
//     }



//builtin func
// class Solution
// {
//     public:
//     vector<int> find(int arr[], int n , int x )
//     {
//         int low = lower_bound(arr, arr + n, x) - arr;
//         int high = upper_bound(arr, arr + n, x) - arr;
//         if (low > high - 1) 
//             return {-1, -1};
//         return {low, high - 1};
//     }

// };