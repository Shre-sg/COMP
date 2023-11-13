#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.
 

// Example 1:

// Input:
// a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
// a2[] = {11, 3, 7, 1, 7}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 2:

// Input:
// a1[] = {1, 2, 3, 4, 4, 5, 6}
// a2[] = {1, 2, 4}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    string ans = "Yes";

    for (int i = 0; i < n; i++) {  //inserting all ele to unordered map
        mp[a1[i]]++;
    }

    for (int i = 0; i < m; i++) {
        if (mp.find(a2[i]) == mp.end() || mp[a2[i]] == 0) {  //cheching if ar2[j] is not present 
            ans = "No"; //if it not present return  no;
            break;
        } else {
            mp[a2[i]]--;  //if present decrement its freq 
    }

}
    return ans;
}  

int main() {
    // Declare and initialize two arrays of integers and their sizes
    int a1[] = {11, 1, 13, 21, 3, 7};
    int n = sizeof(a1) / sizeof(a1[0]);
    int a2[] = {11, 3, 7, 1};
    int m = sizeof(a2) / sizeof(a2[0]);

    // Call the function isSubset and store the return value in a string variable
    string ans = isSubset(a1, a2, n, m);

    // Print the string variable to the standard output
    std::cout << ans << std::endl;

    // Return 0 from the main function
    return 0;
}
