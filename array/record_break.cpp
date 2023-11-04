#include<iostream>

using namespace std;

//brute force is check all prevois ele if it is smaller aas given problem , 
// optamies having a max var to check instead of cheacking alll var

int main(){
    int arr[100];

    int n;

    cout<<"type the no of ele"<<endl; 
    cin>>n;    

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];                ///takes input arry of 8  ele from index 0 to 7 
    }
    
    arr[n]=-1;          ///stores -1 in nth index ie 8 to compre with 7 as menstionede in priblem

   

    int max_var=-1, record_break=0;          ///optamised 
    for(int i=0; i<n; i++){
        if(max_var<arr[i] && arr[i]> arr[i+1])
        {
            record_break++;
        }
        max_var= max(arr[i], max_var);
    }

    cout<<record_break<<endl;

}