#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

// Given a string of characters, find the length of the longest proper prefix which is also a proper 
//suffix.
// NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Example 1:

// Input: s = "abab"
// Output: 2
// Explanation: "ab" is the longest proper 
// prefix and suffix. 
// Example 2:

// Input: s = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest proper 
// prefix and suffix. 
// Your task:
// You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(|s|)


//proper prefix means ex
// Input: s = "abab"   -->a)bab here bab is proper fix    SAME GOES WITH PROPER SUFFIX 
// Output: 2
// Explanation: "ab" is the longest proper 
// prefix and suffix. 
//https://youtu.be/qonx7QjXawg?si=fX3rAqK-OEZfcgd3

class Solution{
  public:
	    // Your code goes here
	    int lps(string s) {
	    	
			int n=s.size();
	    
	    	if(n==1) 
	        	return 0;
	    
	    	vector<int>v(n,0);
	    
	    	for(int i=1, j=0 ;i<n; ){
	   
	        	if(s[i]==s[j]){  // iiiiii     
	            	v[i]=j+1;    //  abcdeacbcdef   // is putting v[i] = j+1; j starts from zero thats why
	                             // j
	            	i++; 
	            	j++;
	        	}
	     
	        	else{
	            	if(j==0) 
	                	i++;
	            	else 
	                	j=v[j-1];
	        	}
	    	}
	    	
			return v[n-1];
		}
};


void rabinKarpAlgo(string & pattern, string & text, int q);

int main() {
  string text = "GEEKS FOR GEEKS";
  string pattern = "GEEK";
  
  int q = 101;
  rabinKarpAlgo(pattern, text, q);
  return 0;
}
