#include <iostream>
#include <vector>
using namespace std;


// Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
// Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


// For string 11211 the IP address possible are 
// 1.1.2.11
// 1.1.21.1
// 1.12.1.1
// 11.2.1.1

// Example 1:

// Input:
// S = 1111
// Output: 1.1.1.1
// Example 2:

// Input:
// S = 55
// Output: -1

class Solution{
  private:
  bool isValid(string s){
     int m=s.length();
     int temp=stoi(s); // coverts string to interger value
     
     if(m==0 || m>3  || (s[0]=='0' && m>1)|| temp<0 || temp>255 )  ///whole logic
        return false;
     
     return true;
  }
  
  public:
    vector<string> genIp(string &s) {
        // Your code here
        int n=s.size();
        vector<string>ans;
        
        if(n>12 || n<4){
            ans.push_back("-1");
            return ans;
        }
        //these loops palces 3" . " at all the points to get ip  
        for(int i=1;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    string a=s.substr(0,i);  //send whatever we to check fun 
                    string b=s.substr(i,j-i);
                    string c=s.substr(j,k-j);
                    string d=s.substr(k,n);
                    
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)){  // cheching if valid
                        ans.push_back(a+"."+b+"."+c+"."+d); //string ans
                    } 
                }
            }
        }
        return ans;
    }

}; 

int main() {
    Solution solution;
    
    // Test case 1: Valid input
    string input1 = "25525511135";
    vector<string> result1 = solution.genIp(input1);
    
    cout << "Test Case 1:\n";
    for (const string& ip : result1) {
        cout << ip << "\n";
    }
    
    // Test case 2: Invalid input
    string input2 = "123456789";
    vector<string> result2 = solution.genIp(input2);
    
    cout << "\nTest Case 2:\n";
    for (const string& ip : result2) {
        cout << ip << "\n";
    }
    
    return 0;
}
