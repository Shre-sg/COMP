#include <iostream>
#include <unordered_map>
using namespace std;

// Given an array of N integers, and an integer K, find the number of pairs of elements in the
// array whose sum is equal to K.

// Example 1:

// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation:
// arr[0] + arr[1] = 1 + 5 = 6
// and arr[1] + arr[3] = 5 + 1 = 6.

// Example 2:

// Input:
// N = 4, K = 2
// arr[] = {1, 1, 1, 1}
// Output: 6
// Explanation:
// Each 1 will produce sum 2 with any 1.

// // if a+b=k(which we have to find out)
// //     then a=k-b; where b is arr[i],k is given , a is maped value ie bacailly we are lookin for a in
// //     the map as we encounter we increase the count by the occurance or freq of mapp then increment the freq;
//      https://youtu.be/5L9Jrehvoew?si=myjln7_b8Fipsb6N

//         a  b             a   currance       ==>  MAP[k-arr[i]] formulae               coount= count +freq
//     EX {1, 5, 7,1 }  ---> 1--->1      (i=0, a=6-1)=5  push arr[i]-->map                COUNT=0
//        k=6           ---> 5 --->1     (i=1,a=6-5)=1  already in map && add 5 to map     COUNT=0+1              COUNT=0+1
//                     --->7--->1       (i=2,a=6-7)=-1    push arr[i] -->map               COUNT=1
//                                      (i=3,a=6-1)=5   already in map              COUNT=0+1+1
//                                      return count =2;

//  refer notes
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        unordered_map<int, int> mp; // it basically stores the <data, its occurance>
        int count = 0;
        int rem = 0;

        for (int i = 0; i < n; i++)
        {
            rem = k - arr[i]; // rem == a in [a =k-b]

            if (mp.find(rem) != mp.end()) // if(map[rem]) also works
                count = count + mp[rem];

            mp[arr[i]]++;
        }

        return count;
    }
};

int main()
{

    Solution sol; // create an object of the Solution class

    int arr1[] = {1, 5, 7, 1}; // test array 1
    int n1 = 4;                // size of test array 1
    int k1 = 6;                // target sum for test array 1

    int arr2[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}; // test array 2
    int n2 = 13;                                               // size of test array 2
    int k2 = 11;                                               // target sum for test array 2

    cout << sol.getPairsCount(arr1, n1, k1) << endl; // print the answer for test case 1
    cout << sol.getPairsCount(arr2, n2, k2) << endl; // print the answer for test case 2

    return 0;
}