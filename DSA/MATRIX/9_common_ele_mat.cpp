#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
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