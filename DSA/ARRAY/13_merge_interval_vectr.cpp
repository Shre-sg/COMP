#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//IMP: Interval is vector inside a vertor, 
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {  //fun returns a vector inside of a vector
        
        if(intervals.size()<=1) //if size of interval vector is 1 or 0 return interval
            return intervals;
        
        sort(intervals.begin(),intervals.end());  //sort needs two arguments --> start  and end; we sorting all ele inside a interval vector 
        
        vector<vector<int>>ans;      //we create a new vector to store ans ie "ans is vetor inside a vector "
        ans.push_back(intervals[0]);   //we add first vector in interval to ans vector 
         
        int j=0;        ///refers to ans end_vector helper index 

        for(int i=1;i<intervals.size();i++){   //loops thru all the vetors of interval vectoor
            
            //compaing the end_point of ans-vec to start_point of interval_vec if its greater we merge
            if(ans[j][1]>=intervals[i][0]){   //comparing one ans vector to all the vector present in interval vector
                
                int t1=ans[j][0];  //start_point of new vec to be added to the ans vec
                int t2=max(intervals[i][1],ans[j][1]);//end_point of new vec to be added into the ans vector
                
                ans.pop_back();  //pop  the old vec from ans
                ans.push_back({t1,t2}); //add the new vec we created to the ans
            }
            else {  
                ans.push_back(intervals[i]);  // If they are not meargeable then just add the new vec to ans
                j++; //increated as new vecc is added
            }

        }
        return ans;
    }
};

int main() {
    
    vector<vector<int>> intervals = {{1,3}, {2,4}, {6,8}, {9,10}}; //vec inside a vec creation
    
    Solution s; // creating an instace of object class
    vector<vector<int>> merged = s.merge(intervals);
    cout << "Merged intervals: ";
    
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
