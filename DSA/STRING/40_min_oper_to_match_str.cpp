#include <bits/stdc++.h>
using namespace std;

// Transform One String to Another using Minimum Number of Given Operation

// Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

// Examples: 

// Input:  A = "ABD", B = "BAD"
// Output: 1
// Explanation: Pick B and insert it at front.
// Input:  A = "EACBD", B = "EABCD"
// Output: 3
// Explanation: Pick B and insert at front, EACBD => BEACD
//              Pick A and insert at front, BEACD => ABECD
//              Pick E and insert at front, ABECD => EABCD



// Algorithm:

// We declare a HashMap<Character,Integer> to store frequency map.
// We store the character of string 1 in the map and then while traversing string 2 ,we erase the characters and if the map is empty at the end that means the characters in both the string are same and we can continue,else we return -1.
// We make a variable res and point two pointer i and j to the last of both strings and start traversing from back.
// As soon as see a ith character that doesn’t match with jth character ,we start increasing res by 1 until again both the characters are same.
// Atlast we return res.

int transform(string A, string B)
{
	if (A.length() != B.length()) {
		return -1;
	}
	// create a map to store the frequency of characters in string A
	unordered_map<char, int> m;   /// check if both str has same lertters or not
	int n = A.length();
	for (int i = 0; i < n; i++) {
			m[A[i]]++;	 
	}

	// subtract the frequency of characters in string B from the map
	for (int i = 0; i < n; i++) {
			if(m.find(B[i])!=m.end())
                m[B[i]]--;
            else
                return -1;
	}
	// check if all the frequencies in the map are 0, indicating equal frequency of characters in both strings
	for (auto it : m) {
		if (it.second != 0) // if frequency is not zero
			return -1;	 // strings cannot be transformed into each other, return -1
	}
//////MAIN ALGO
	// calculate the minimum number of operations required to transform string A into string B
	int i = n - 1, j = n - 1;
	int res = 0;
	while (i >= 0 && j >= 0) {
		while (i >= 0 && A[i] != B[j]) {
			res++; // increment the number of operations required
			i--;	 // move the pointer i to the left
		}
		i--;
		j--;
	}
return res; // returning result
}

// Driver code
int main()
{
	string A = "EACBD";
	string B = "EABCD";

	cout << "Minimum number of operations required is " << transform(A, B) << endl;
	return 0;
}
