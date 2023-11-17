#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int j=s.size()-1;
        int i=0;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main() {
    // Create an object of the Solution class
    Solution sol;
    // Create a vector of characters
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    // Print the original vector
    cout << "Original vector: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << "\n";
    // Call the reverseString function
    sol.reverseString(s);
    // Print the reversed vector
    cout << "Reversed vector: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << "\n";
    // Return 0 to indicate success
    return 0;
}
