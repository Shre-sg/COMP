#include <bits/stdc++.h>
using namespace std;

// WE CAN USE THIS CODE FOR 2-ICE BUY SELL ONLY TO WITH CAP VARIABLE 

long f(int index, int buy, long *values , int n){
    
    if(index==n){  ///base case when the index is more than n+1 ie ranout
        return  0;
    }

    long profit =0;
    if(buy){          ///when buy is det to one we are able to buy
        profit =max(-values[index] + f(index+1, 0, values, n) ,  0 + f(index+1, 1, values, n));
        //profit is max( ) either you buy stock at index (-values is added) or dont buy ie ( 0 is added) called f again for nextindex;
    }
        // PROFIT = - PRICE BOUGHT  + PRICE SELLED 

    else{
        profit = max(values[index] + f(index+1, 1, values, n)  ,  0 + f(index+1, 0, values,n));
        //profit is max ( ), sell ( vales is added), next index is free to  buy, or dont sell ( 0 is added) and next index is not  free to buy
    }
    return profit;
}

long getmaxprofit(long *values, int n){
    return f(0,1,values,n);
}

// main code
int main() {
    // input the number of values
    int n;
    cin >> n;

    // input the values as an array
    long values[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // call the function to get the maximum profit
    long maxprofit = getmaxprofit(values, n);

    // output the result
    cout << "The maximum profit is " << maxprofit << endl;

    return 0;
}
