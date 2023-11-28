#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Given an array of strings, return all groups of strings that are anagrams.
//The groups must be created in order of their appearance in the original array. 
//Look at the sample case for clarification.
//Note: The final output will be in lexi-cographic order.


// Example 1:
// Input:
// N = 5
// words[] = {act,god,cat,dog,tac}
// Output:
// act cat tac 
// god dog
// Explanation:
// There are 2 groups of
// anagrams "god", "dog" make group 1.
// "act", "cat", "tac" make group 2. 

// Example 2:
// Input: 
// N = 3
// words[] = {no,on,is}
// Output: 
// is
// no on
// Explanation:
// There are 2 groups of
// anagrams "is" makes group 1.
// "no", "on" make group 2.

// Your Task:
// The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.


// Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
// Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.




class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& str) {

        unordered_map<string,vector<string>> mp;  //xplained below
        vector<vector<string>> ans;  //stroring ans 


        for(int i=0; i<str.size(); i++){    //runs thru all the words not char in input list 
            string list = str[i];           //this contrians whole word like "cat" not char
            sort(list.begin(),list.end());  //sorting the letters in the word  like cat -->act
            mp[list].push_back(str[i]);     //here act acts as index, like string act ---> cat, tac etc
        }
 
        for(auto i : mp){      ///from map i am importing it to out ans vector
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> str = {"act", "cat", "dog", "god", "tac"};
    vector<vector<string>> ans = s.Anagrams(str);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}


//EXPLAIN for unordered_map<string, vector<string>> map
//strring list= "Fruits"; 
//map[list]
//Friuts--> apple, //one pushback
//FRuitts -->apple, banana //second ushback
//map[list="veg"];
//veg--->carrot etc;

// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main() {
//     unordered_map<string, vector<string>> mp;
//     mp["fruit"].push_back("apple");
//     mp["fruit"].push_back("banana");
//     mp["fruit"].push_back("orange");
//     mp["vegetable"].push_back("carrot");
//     mp["vegetable"].push_back("potato");
//     mp["vegetable"].push_back("onion");

//     for (auto it = mp.begin(); it != mp.end(); it++) {
//         cout << it->first << ": ";
//         for (auto i : it->second) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
