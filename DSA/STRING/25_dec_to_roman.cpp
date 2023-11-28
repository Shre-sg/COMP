#include <iostream>
#include <vector>
#include <string>
using namespace std;

// The given code for the Solution class
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string> notations = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        //must note down all the all these values
        for(int pos = 0; num>0; ++pos){  // to go thru the value vector to compare with num
            while(num >= value[pos]){  //as num is greater we add the CHAR to roman else we recudes the chechk value of the value vector
                roman += notations[pos];
                num -= value[pos];
            }
        }
        return roman;
    }
};

//USING MAPS
// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<pair<int, string>> map{{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, 
// 		{90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
//         int l = map.size()-1;
//         string s="";
        
//         while(num!=0){
//             while(map[l].first>num){   //do till we find when num>> map.first
//                 l--;-
//             }
//             s += map[l].second;
//             num -= map[l].first;
//         }
//         return s;
//     }
// };

// The main function
int main() {
    // Create an object of the Solution class
    Solution sol;

    // Declare an integer variable to store the decimal number
    int num;

    // Prompt the user to enter a decimal number
    cout << "Enter a decimal number: ";

    // Read the input from the user
    cin >> num;

    // Call the intToRoman method of the Solution class and store the result
    string result = sol.intToRoman(num);

    // Print the result
    cout << "The roman numeral of " << num << " is " << result << endl;

    // Return 0 to indicate successful termination
    return 0;
}
