
#include<bits/stdc++.h>
using namespace std;


// Minimum characters to be added at front to make string palindrome

// Given string str we need to tell minimum characters to be added in front of the string to make string palindrome.

// Examples: 

// Input  : str = "ABC"
// Output : 2
// We can make above string palindrome as "CBABC"
// by adding 'B' and 'C' at front.
// Input  : str = "AACECAAAA";
// Output : 2
// We can make above string palindrome as AAAACECAAAA
// by adding two A's at front of string.


//---->algo works as to make a str to pal we need as char from first, 
//one more way is to remove char from last to make it as a palin ,,

///--->2nd allgo is basically added same give word from first, then check for pal not down the 
//char requred, then remove one char from first check again if palin note down the min char reqired
//to form pal , do this till n/2; retyrn the min char requirede ans we got 

// function for checking string is palindrome or not
bool ispalindrome(string s)
{
	int l = s.length(); 
	int j;
	
	for(int i = 0, j = l - 1; i <= j; i++, j--)
	{
		if(s[i] != s[j])
			return false;
	}
	return true;
}

// Driver code
int main()
{
	string s = "BABABAA";
	int cnt = 0;
	int flag = 0;
	
	while(s.length()>0)   ///till  lenght is less thn 0
	{
		// if string becomes palindrome then break
		if(ispalindrome(s))
		{
			flag = 1;   //
			break;
		}
		else
		{
		cnt++;  //incerased as last should be removed to get palindrome
		
		// erase the last element of the string  and check again palin
		s.erase(s.begin() + s.length() - 1);  /// same as (s.lenght()-1)
		}
	}
	
	// print the number of insertion at front
	if(flag)
		cout << cnt;
}
