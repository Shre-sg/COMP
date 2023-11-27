#include <bits/stdc++.h>
using namespace std;

//https://takeuforward.org/string/rabin-karp-algorithm-pattern-searching/
// Rabin Karp Algorithm
// Before starting, let’s understand the hash function.

// Hash Function: It’s a function that is used to map data to fixed values. 
//Eg: A function that converts a big phone number to a small practical integer value. 
//This function maps a big number or string to a small integer that can be used as the index in 
//the hash table.
// So, let’s define a Hash Function for our algorithm. Let’s denote each letter of the alphabet with 
//a code like, a is represented by 1, b is represented by 2, c – 3, d-4, ….z=26.

// Let’s take an example of how this will help us. 

// Text = “aaaaab”,Pattern= “aab”
// Now as mentioned in the image, aab is represented by an integer which is 4 . We also got a substring in the Text string whose integer value is also 4. This value is called Hashcode.
// After getting the same hashcode, we need to cross-check whether both the strings are equal or not. In the above case, it’s equal.
// Now, this method has a DRAWBACK. After this, we will learn the actual algorithm. 
// Let’s take an example, text=”ccaccaaedba”, pattern=”dba”

// As we can see the hashcodes of a substring of text are matching with the hashcode of the pattern but both strings are not the same. In this way, we are comparing patterns every time and it is not matching every time ( except “dba” in the above case) 

// If we take such a simple Hash Function, there’s a possibility of collision with the other substrings which are having the same code though they are not patterns. This is also called Spurious Hits.
// In such a situation, the maximum time taken by the algorithm may be O(m*n).
// We selected such a type of hash function which is causing such Spurious Hits. So we need to change the Hash function.
// Now from here, we’ll be learning the actual algorithm.
// Hash Function = (pattern[0]*(x^m-1) + pattern[1]*(x^m-2) + pattern[2]*(x^m-2) + ….pattern[m-1]*(x^0)) % MOD.

// Here, x = base value ( number of alphabets used, if 26 alphabets are used in the text , then x=26 )
// m = length of pattern.
// Inorder to minimize spurious hits, we use modulus.



void rabinKarpAlgo(string & pattern, string & text, int q) {

  int m = pattern.size();
  int n = text.size();
  int i, j, hash_p = 0, hash_t = 0, h = 1, d = m + n;

  for (i = 0; i < m - 1; i++) {
    h = (h * d) % q;
  }

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    hash_p = (pattern[i] + d * hash_p) % q;
    hash_t = (text[i] + d * hash_t) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {

    // Check the hash values of current windows of text and pattern.
    if (hash_p == hash_t) {

      for (j = 0; j < m; j++) {

        if (text[i + j] != pattern[j]) break;
      }

      // if pattern == text
      if (j == m) cout << "Pattern is found at index : " << i << "\n";
    }

    // Calculate the hash value for next window : adding trailing digit 
   //and remove leading digit
    if (i < n - m) {
      hash_t = (d * (hash_t - text[i] * h) + text[i + m]) % q;

      //converting negative value of hash_t to positive.
      if (hash_t < 0) hash_t = (hash_t + q);
    }
  }
}

int main() {
  string text = "GEEKS FOR GEEKS";
  string pattern = "GEEK";
  int q = 101;
  rabinKarpAlgo(pattern, text, q);
}