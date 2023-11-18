#include<bits/stdc++.h>
using namespace std;
 
//see notes a&&  take u forward video of printing all subseq of 
// 3 1 2
// 3 1
// 3 2
// 3
// 1 2
// 1
// 2

void solve(int i, vector <int> s, int arr[], int n ) {
	if (i == n) {
		for(auto it : s){
            cout<< it <<" ";
        }
        cout <<endl;
		return;
	}
    
	//add ele to as to print
	s.push_back(arr[i]);
	solve(i + 1, s, arr, n);
	
    //poping out while backtracking
	s.pop_back();
	solve(i + 1, s,  arr, n);
}

int main() {
	int arr[] = {3,1,2};
    int n=3;
    vector <int> s;
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, arr, n);
    return 0;
}