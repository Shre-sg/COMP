#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 


// Given an m x n matrix, find all common elements present in all rows in O(mn) time
// and one traversal of matrix.

// Example: 

// Input:
// mat[4][5] = {{1, 2, 1, 4, 8},
//              {3, 7, 8, 5, 1},
//              {8, 7, 7, 3, 1},
//              {8, 1, 2, 7, 9},
//             };

// Output: 
// 1 8 or 8 1
// 8 and 1 are present in all rows.    



// Function to find the common elements in all the rows of the specified matrix
void findCommon(vector<vector<int>> const &mat)
{
    // base case
    if (mat.size() == 0) {
        return;
    }
 
    unordered_map<int, int> map;
 
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            map[mat[i][j]]++;
        }
    }

    for(auto it : map){
        if(it.second>=4){
            cout<<it.first<<endl;
        }
    }
}

 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 4, 3, 8, 7 },
        { 4, 7, 1, 3, 6 },
        { 3, 5, 2, 1, 3 },
        { 1, 5, 0, 2, 3 },
    };
 
    findCommon(mat);
 
    return 0;
}