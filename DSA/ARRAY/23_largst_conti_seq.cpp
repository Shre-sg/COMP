#include <iostream>
#include <unordered_map>
using namespace std;



// Given an array of positive integers. Find the length of the longest sub-sequence such that 
//elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6
// Explanation:
// The consecutive numbers here
// are 1, 2, 3, 4, 5, 6. These 6 
// numbers form the longest consecutive
// subsquence.

// Example 2:
// Input:
// N = 7
// a[] = {1,9,3,10,4,20,2}
// Output:
// 4
// Explanation:
// 1, 2, 3, 4 is the longest
// consecutive subsequence.

// algo is find max ele in array; then iter from 0  to maxele noted down the
// continuing seq; by checking for it in the hash map; i9f found increae the
// ciount or reset the count ; while doing keep the tabs of the largest one

int findLongestConseqSubseq(int arr[], int N) {
    //Your code here
    int maxi = 0,
    cnt = 0,
    maxel = 0;

    unordered_map<int, int> m; //add all ele it the map

    for (int i = 0; i < N; i++) {
        m[arr[i]]++; //adding to map
        maxel = max(maxel, arr[i]); //noting down the lagest ele
    }

    for (int i = 0; i <= maxel; i++) { //algo starts from 0
        if (m.find(i) != m.end()) { // if the ith ele is not found in the map it returns the ppointer to maps end;
            cnt++;                      //counting the max continung array
            maxi = max(maxi, cnt);   ///
        } 
        else 
            cnt = 0;   //not found reset to zero
    } 
    return maxi;
}

int main() {
    // Input the size of the array
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    // Input the elements of the array
    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // Call the findLongestConseqSubseq method and store the result in an int
    // variable
    int result = findLongestConseqSubseq(arr, N);
    // Print the result
    cout << "The length of the longest consecutive subsequence is: " << result << endl;
    return 0;
}
