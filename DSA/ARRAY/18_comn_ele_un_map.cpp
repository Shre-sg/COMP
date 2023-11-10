#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// Example 1:

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.


class sol {
    public:    
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_map<int,int> count;
            
            for(int i=0;i<n1;i++){
                if(count[A[i]]==0){   //(count[A[i]]==0)  count.count(A[i])==0
                    count[A[i]]++;  /// (a[i],1) inserted to map  //count.insert(make_pair(A[i]),1); 
                }
            }
            
            for(int i=0;i<n2;i++){
                if(count[B[i]]>0 && count[B[i]]==1){
                    count[B[i]]++;
                }
            }
            
            for(int i=0;i<n3;i++){
                if(count[C[i]]>0 && count[C[i]]==2){
                    count[C[i]]++;
                }
            }
            
            vector<int> rst;
            for(auto it : count){
                if(it.second==3){             ///(first,second) ie we are refrencing to freq
                    rst.push_back(it.first);
                }
            }
            
            if(rst.empty()){
                rst.push_back(-1);
            }
            
            sort(rst.begin(), rst.end());
            return rst;
        }
};

int main(){
    sol s; // create an object of the sol class
    
    int A[] = {1, 5, 10, 20, 40, 80}; // test array A
    int B[] = {6, 7, 20, 80, 100}; // test array B
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120}; // test array C
    
    int n1 = sizeof(A)/sizeof(A[0]); // size of test array A
    int n2 = sizeof(B)/sizeof(B[0]); // size of test array B
    int n3 = sizeof(C)/sizeof(C[0]); // size of test array C
    
    vector<int> rst = s.commonElements(A,B,C,n1,n2,n3); // call the commonElements method and store the result in a vector
    
    for(int x : rst){ // loop through the vector and print the elements
        cout << x << " ";
    }
    
    cout << endl;
    return 0;
}