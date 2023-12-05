#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.
// Example 2:

// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and 
// smallest positive missing number is 2.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        map<int,int>m;
        vector<int>ans;
        //finding the re[eated ele]
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
            
            if(m[arr[i]]>1)
            {
               ans.push_back(arr[i]);
               break;
            }
        } 
        //finging the mssing number
        int k=1;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==k)
            {
                k++;
            }
        }
         ans.push_back(k);
        
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    int n = arr.size();
    Solution obj;
    vector<int> result = obj.findTwoElement(arr, n);
    cout << "Repeated element: " << result[0] << endl;
    cout << "Smallest positive integer not present in arr: " << result[1] << endl;
    return 0;
}
