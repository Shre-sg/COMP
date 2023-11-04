#include<iostream>

using namespace std;

//loop over the arrya and find the answer
//step1; maintain prevoius diff and the current diff
//step2; maintain current arthematic subarray length 
//step3; max subarry length

int main(){
int arr[100];

    int key, n;

    cout<<"type the no of ele"<<endl; 
    cin>>n;   

    cout<<"type the ele"<<endl;    
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }

    int prev_len =2; //acts a storing ans as well
    int cur_len =2;

    int pd = arr[1] - arr[0];
    int j=2; //index to start next 

    while(j<n){
        if(pd == arr[j]- arr[j-1]){
            cur_len++;
        }
        else{
            pd == arr[j]- arr[j-1];
            cur_len=2;
        }
        prev_len= max(prev_len, cur_len);
        j++;

    }

    cout<< prev_len<<endl;
    

}