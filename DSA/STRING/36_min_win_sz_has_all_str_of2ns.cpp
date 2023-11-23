#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;



// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

// Example 1:

// Input:
// S = aabb
// Output:  ab 
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.

// Example 2:

// Input:
// S = aabaa
// Output:  aba
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// 'a' at fifth position is appearing
// 2nd time consecutively.
 

// Your Task:
// You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.
 

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
            need++;      ///it stores all letter count we neeed 
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
