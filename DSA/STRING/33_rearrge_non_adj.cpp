#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

// Example 1:

// Input : str = "geeksforgeeks"
// Output: 1
// Explanation: All the repeated characters of the
// given string can be rearranged so that no 
// adjacent characters in the string is equal.
// Any correct rearrangement will show a output
// of 1.
// Example 2:

// Input : str = "bbbbb"
// Output: 0
// Explanation: Repeated characters in the string
// cannot be rearranged such that there should not
// be any adjacent repeated character.
// Your task :
// You don't have to read input or print anything. Your task is to complete the functionrearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
// Note:The generatedoutput is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
// Expected Time Complexity : O(NlogN), N = length of String
// Expected Auxiliary Space : O(number of english alphabets)

//https://youtu.be/v3f30xiaPVc
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        unordered_map<char,int>map;   //to keep track of letters and its freq
        int n =str.length();
        
        if(n<2)
        {
            return str;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            map[str[i]]++;  // adding all ele
        }
        
        //C++ STL, the top element is always the greatest by default. We can also change it to the 
        //smallest element at the top. Priority queues are built on the top of the max heap and 
        //use an array or vector as an internal structure

        priority_queue<pair<int,char>> pq;  //
        
        for(auto it:map)  
        {
            if( it.second > (n+1)/2)  /// as no of max char is greater than n+!/2 its not possible to balance
            {
                return "-1";
            }
            pq.push(make_pair(it.second,it.first)); //pushing the pair to que
        }
        
        
        
        string ans (n,'a');  //creating a ans string wiht size n and initialised to a 
        int idx=0;  // to run thru n staring 0
        while(!pq.empty()) 
        {
            pair<int,char> top = pq.top();   //gretaest on will be loaded
            
            while(top.first)      
            {
                if(idx>=n)  ///till fi reaches end reset
                {
                    idx=1;  //straing to fill odd places 
                }
                ans[idx]=top.second; //addind char to that postion
                idx+=2;  //move from even ans odd 
                top.first--; //decemnenting the freq
            }
            
            pq.pop(); //pop out the top
        }
        
        return ans;
        
        
    }
       
};

int main()
{
    Solution s;
    string str = "aaabbc";
    cout << s.rearrangeString(str) << endl;
    return 0;
}


// class Solution
// {
//     public:
//     string rearrangeString(string str)
//     {
//         int n = str.length();
//         string ans = "";                             ///IMPORT
//         // take a map
//         unordered_map<char,int> m;
//         // map all the chars 
//         for(auto i:str){
//             m[i]++;
//         }
//         // take one priority queue according its frequency
//         priority_queue<pair<int,char> > pq;
//         for(auto i:m){
//             pq.push({i.second, i.first});
//         }
        
//         while(pq.size() > 1){
//             pair<int, char> p1 = pq.top();
//             pq.pop();
//             p1.first--;
//             ans += p1.second;                                    ///IMPO another way to manupulate
            
//             pair<int, char> p2 = pq.top();
//             pq.pop();
//             p2.first--;
//             ans += p2.second;
            
//             if(p1.first) pq.push({p1.first, p1.second});
//             if(p2.first) pq.push({p2.first, p2.second});
            
//         }
        
//         // if there is something left over
//         if(pq.size()){
//             if(pq.top().first == 1){
//                 ans += pq.top().second;
//             }
//             else return "-1";
//         }
//         return ans;
        
//     }
       
// };