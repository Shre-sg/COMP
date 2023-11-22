#include <iostream>
#include <climits>
#include<bits/stdc++.h>

using namespace std;


// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"


//ALGO: 
//basicall algo works as as add all the unique ele to map, map size will give window size, 
// i run a window size on array if the again windown size matches will the map size i got the answer 
// ie i store the ans now i reduce the window size by decreasing i ; ie removing ith ele , 
class Solution {
public:
    int findSubString(string str) {
        unordered_map<char, int> map, map1;

        for (auto it : str)
            map[it]++;

        int i = 0, j = 0, ans = INT_MAX;

        while (j < str.size()) {
            map1[str[j]]++;

            while (map1.size() == map.size()) {
                ans = min(ans, j - i + 1);
                map1[str[i]]--;

                if (map1[str[i]] == 0)     //This code is needed to maintain the size of the map map1 
                      map1.erase(str[i]);   //as the window slides. The map map1 stores the frequency of each character 
                                            //in the current window. When you move the left pointer i forward, 
                                                ///you decrease the frequency of the character str[i] by one. 
                                                //If the frequency becomes zero, then you erase that character from the map. This way, you keep only the characters that 
                                                //are present in the current window in the map. This helps you to check if the current window contains all characters of the pattern by 
                                                //comparing the size of map1 and map. If they are equal, then it means that the current window is valid.
                    
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "ADOBECODEBANC";
    string test2 = "ABC";
    string test3 = "AAAAAA";
    string test4 = "ABCD";

    cout << "Test 1: " << solution.findSubString(test1) << endl;
    cout << "Test 2: " << solution.findSubString(test2) << endl;
    cout << "Test 3: " << solution.findSubString(test3) << endl;
    cout << "Test 4: " << solution.findSubString(test4) << endl;

    return 0;
}
