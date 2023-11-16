#include <iostream>
#include <bits/stdc++.h>
#include<climits>
using namespace std;


// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.


class Solution {
public:
    int maxProfit(vector<int>& prices){
        
        int minPrice = INT_MAX; // initialize minPrice to a large value
        int maxProfit = 0; // initialize maxProfit to zero
        
        for(int price : prices){ // loop through the prices array
            if(price < minPrice){ // if the current price is lower than minPrice
                minPrice = price; // update minPrice
            }
            else{ // else
                maxProfit = max(maxProfit, price - minPrice); // update maxProfit with the current profit
            }
        
        }
        return maxProfit; // return the final answer
    }
};


int main(){
    Solution sol; // create an object of the Solution class
    vector<int> prices1 = {7,1,5,3,6,4}; // test case 1
    vector<int> prices2 = {7,6,4,3,1}; // test case 2
    cout << sol.maxProfit(prices1) << endl; // print the answer for test case 1
    cout << sol.maxProfit(prices2) << endl; // print the answer for test case 2
    return 0;
}


//another way of thinking 
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int min_ = INT_MAX; ///it bascially  day you bought price
        int max_profit = 0;
        int profit = 0;  //profit if sold at the ith day
        
        for(int i = 0; i < prices.size(); i++){
            
            if(prices[i] < min_){
                min_ = prices[i];
            }

            profit = prices[i] - min_; //calculating profit @ ith day
            
            if(max_profit < profit){   //assings max profit
                max_profit = profit;
            }
        }
        return max_profit;
    }
};