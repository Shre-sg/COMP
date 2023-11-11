#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
 


class Solution {
public:
   int maxProfit(vector<int>& prices) {
        
        if(!prices.size())
            return 0;
        
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        
        for(int i = 0; i < prices.size(); i++){  
            buy1    = min(buy1, prices[i]);    //min ----> price we buy
            profit1 = max(profit1, prices[i] - buy1);  // max---> price we sell && prices-buy1 will give profit
            buy2    = min(buy2, prices[i] - profit1);   //min ----> price we buy
            profit2 = max(profit2, prices[i] - buy2);  // max---> price we sell && prices-buy1 will give profit
        }
        
        return profit2;
    }
};

int main() {
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // Input the elements of the array
    vector<int> prices(n);
    cout << "Enter the prices of the stock on each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    // Create an object of Solution class
    Solution sol;
    // Call the maxProfit method and store the result in an int variable
    int result = sol.maxProfit(prices);
    // Print the result
    cout << "The maximum profit you can achieve with at most two transactions is: " << result << endl;
    return 0;
}
