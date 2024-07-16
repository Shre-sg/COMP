#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];


    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int maxnum=arr[0];
    int minnum=arr[0];


    for(int i=0; i<n; i++){
        maxnum=max(maxnum,arr[i]);
        minnum=min(minnum,arr[i]);
    }

    cout<<maxnum<<endl;
    cout<<minnum<<endl;

}