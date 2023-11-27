/*

Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
Video Solution : https://youtu.be/YOnbzPRfwF0

*/

// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid.
// A word can be matched in all 8 directions at any point. Word is said to be found in a direction if 
//all characters match in this direction (not in zig-zag form). 
//The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

// Note: The returning list should be lexicographically smallest. If the word can be found in 
//multiple directions starting from the same coordinates, the list should contain the coordinates 
//only once. 

// Example 1:
// Input: 
// grid = {{a,b,c},{d,r,f},{g,h,i}},
// word = "abc"
// Output: 
// {{0,0}}
// Explanation: 
// From (0,0) we can find "abc" in horizontally right direction.

// Example 2:
// Input: 
// grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
// word = "abe"
// Output: 
// {{0,0},{0,2},{1,0}}
// Explanation: 
// From (0,0) we can find "abe" in right-down diagonal. 
// From (0,2) we can find "abe" in left-down diagonal. 
// From (1,0) we can find "abe" in horizontally right direction.

//a b a b   a             a
//a b e b     b         b     a b e
//e b e b       e     e

// Your Task:
// You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

// Expected Time Complexity: O(n*m*k) where k is constant
// Expected Space Complexity: O(1)



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
		int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };  //dirctions
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int n = grid.size();   ///row
        int m = grid[0].size();   //col
        
        vector<vector<int>> ans;
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return grid[x][y] == word[p];
        };
        
        function<bool(int, int, int, int)> helper = [&](int x, int y, int dir, int p) -> bool {
            
			if(p == word.size() - 1)
                return 1;
                
            if(valid(x + dx[dir], y + dy[dir], p + 1))
                return helper(x + dx[dir], y + dy[dir], dir, p + 1);
                
            return 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    if(valid(i, j, 0) and helper(i, j, k, 0)){
                        vector<int> t = {i, j};
                        ans.push_back(t);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	
	int tc;
	cin >> tc;
	
	while(tc--){
		int n, m;
		cin >> n >> m;
		
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		
		string word;
		cin >> word;
		
		Solution obj;
		
		vector<vector<int>>ans = obj.searchWord(grid, word);
		
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
				for(auto j: i)
					cout << j << " ";
			cout << "\n";
			}
		}
		
		
	}
	return 0;
}
// } Driver Code Ends