#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// Given two strings S and P. Find the smallest window in the string S consisting of 
//all the characters(including duplicates) of the string P.  Return "-1" in case there is no such 
//window present. In case there are multiple such windows of same length, return the one with the 
//least starting index.
// Note : All characters are in Lowercase alphabets. 

// Example 1
// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.

// Example 2:
// Input:
// S = "zoomlazapzo"
// P = "oza"
// Output: 
// apzo
// Explanation: "apzo" is the smallest 
// substring in which "oza" can be found.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(n) n = len(p)

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).



class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
  string smallestWindow (string s, string p)

    {
        int start_idx=0,j=0,len=INT_MAX;
        vector<int>v(26,0);             //stores the pattren char cuccreance num
        
        for(int i=0;i<p.size();i++){      
            v[p[i]-'a']++;       //ex p[i]=c, then p[i]-'a' will return 2;
        }

        int need=0;
        for(int i=0;i<26;i++){
            if(v[i]!=0)
            need++;      //it stores all letter count we neeed 
        }

        int have=0;   // it stores all the letter count we have as we progress with test string
        vector<int>cur(26,0);   //stores the cuurrance of test str freq
       
        for(int i=0;i<s.size();i++){            //j --------i >>>---------- n 
            
            cur[s[i]-'a']++;                    //adding to currr vector stors req
            
            if(v[s[i]-'a'] == cur[s[i]-'a'])     ////  if the freq of vec v == vec cur ie i have found one char 
                have++; 
            
            while(have==need){     // when all freq is found 
               
                if(len>(i-j+1)){    //string lenght when all is found  ie min lenght 
                    len=i-j+1;
                    start_idx=j;
                }

                cur[s[j]-'a']--;  //moving a " j"  ie removing the ele 
                 
                if(v[s[j]-'a']>cur[s[j]-'a'])   // we hav more freq ele which is in pattren 
                    have--;
                
                j++;
            }
        }
        
        if(len==INT_MAX)
            return "-1";
        
        string ans=s.substr(start_idx,len);  //collecting the substring
        
        return ans;
    }

};

int main()
{
    Solution sol;
    string s = "timetopractice";
    string p = "toc";
    string result = sol.smallestWindow(s, p);
    cout << "The smallest window is: " << result << endl;
    return 0;
}
