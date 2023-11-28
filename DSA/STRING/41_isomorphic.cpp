
#include<bits/stdc++.h>

using namespace std;

//https://youtu.be/6Qkail843d8?si=LpWR6mqdZHX_orff
// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// If the characters in str1 can be changed to get str2, then two strings, str1 and str2, 
//are isomorphic. A character must be completely swapped out for another character while 
//maintaining the order of the characters. A character may map to itself, but no two characters may 
//map to the same character.

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 
// 1
// Explanation: 
// There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
// Example 2:

// Input:
// str1 = aab
// str2 = xyz
// Output: 
// 0
// Explanation: 
// There are two different characters in aab but there are three different charactersin xyz. So there won't be one to one mapping between str1 and str2.



//another wayway of doing is using HASHMAP<char,char> and one haskmap<char, bool>
//instert as they scxanned, insert HASH map wITh maping str1 to str2,  then make str2 to true, if diffrent mapping
//is found and hash map of that str2 is true ie it will be false


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
       if(str1.length() != str2.length())
        {
            return false;
        }
        map<char,char>mymap;
        map<char,char>mymap2;
        
            for(int i = 0; i < str1.length(); i++){
                mymap[str1[i]]=str2[i];    //str1--->str2
                mymap2[str2[i]]=str1[i];   //str2--->str1
                
            }

            for(int i = 0; i < str1.length(); i++){
                if(mymap[str1[i]]!=str2[i] || mymap2[str2[i]] !=str1[i]){   //checking if map is same or not 
                    return false;
                }
            }
 
 
            return true;
            
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}