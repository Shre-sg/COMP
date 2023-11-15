#include <iostream>
#include <vector>
using namespace std;


// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

// Note: The generated output is 1 if you modify the given array successfully.


// Example 1:

// Input: 
// n = 5
// A[] = {1, 2, 3, 3, 4}
// [a, b] = [1, 2]
// Output: 1
// Explanation: One possible arrangement is:
// {1, 2, 3, 3, 4}. If you return a valid
// arrangement, output will be 1.


// Example 2:

// Input: 
// n = 3 
// A[] = {1, 2, 3}
// [a, b] = [1, 3]
// Output: 1
// Explanation: One possible arrangement 
// is: {1, 2, 3}. If you return a valid
// arrangement, output will be 1.




void threeWayPartition(vector<int > & arr, int a, int b) {
    int left=0,i=0,end=arr.size()-1;

    while(i<=end) {  //iterate i till end
        if(arr[i]<a) {               ///if arr[i]<<< a swap
            swap(arr[i],arr[left]);  /// swapping
            i++;                  ///increment the index
            left++;                 //increment left as well
        }
        else if(arr[i] > b) {          // if ele is >>> than b move it to  last of the ARR
            swap(arr[end],arr[i]);  //SWAPPIMG
            end--;                  //MOVE END BUT NOT INDEX i as it is not processed
        }
        i++; ////this means that ele scanneed is between or euall a && b
    }
}


int main()
{
    vector<int> arr = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int a = 10, b = 20;
    threeWayPartition(arr, a, b);
    cout << "The partitioned array is: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
