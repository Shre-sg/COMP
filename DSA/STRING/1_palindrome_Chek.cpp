#include <iostream>
#include <string>
using namespace std;

class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int i=0;
	    int j=S.length()-1;
	    while(i<j){
	        if(S[i]!=S[j])
	            return 0;
	       i++;
	       j--;
	    }
	    return 1;
	       
	}

};

int main() {
    // Create an object of the Solution class
    Solution sol;
    // Create a string variable
    string s;
    // Read a string from the user
    cout << "Enter a string: ";
    cin >> s;
    // Call the isPalindrome function
    int result = sol.isPalindrome(s);
    // Print the result
    if (result == 1) {
        cout << "The string is a palindrome.\n";
    }
    else {
        cout << "The string is not a palindrome.\n";
    }
    // Return 0 to indicate success
    return 0;
}
