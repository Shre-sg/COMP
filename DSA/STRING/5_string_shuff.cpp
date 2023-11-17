// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

// Checking valid shuffle of two Strings

// Given two strings str1 and str2, and a third-string shuffle, determine if shuffle is a valid shuffle of str1 and str2, where a valid shuffle contains all characters from str1 and str2 occurring the same number of times, regardless of order. Print “YES” if valid, and “NO” otherwise.

// Examples: 

// Input: str1 = BA, str2 = XY, shuffle = XYAB 
// Output: YES

// Input: str1 = BA, str2 = XY, shuffle = XUMB 
// Output: NO

// Input: str1 = ABC, str2 = ZYS, shuffle = YBAZSC 
// Output:YES


bool validShuffle(string str1, string str2, string shuffle)
{

	// n1 = size of str1, n2 = size of str2
	int n1 = str1.size();
	int n2 = str2.size();
	int n = shuffle.size();

	if (n != n1 + n2)
		return false;

	 	
	unordered_map<int, int> freq;  //We use an unordered map to keep track of frequency of each character.

	// Count frequency of each char
	// in str1
	for (int i = 0; i < n1; i++)
		freq[str1[i]]++;

	// Count frequency of each char
	// in str2
	for (int i = 0; i < n2; i++)
		freq[str2[i]]++;

	// If any of the char is not found inthe map, then its not avalid shuffle.
	for (int i = 0; i < n; i++) {
		if (freq.find(shuffle[i]) != freq.end())
			freq[shuffle[i]]--;
		else
			return false;
	}
	return true;
}

// Drivers code
int main()
{
	string str1 = "BA", str2 = "XY", shuffle = "ABYX";

	(validShuffle(str1, str2, shuffle) == true)
		? printf("YES")
		: printf("NO");
	cout << endl;

	return 0;
}
