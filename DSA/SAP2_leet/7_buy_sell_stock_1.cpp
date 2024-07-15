// 121. Best Time to Buy and Sell Stock //one buys

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

// Constraints:
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0; // Return 0 if prices is empty

        int profit = 0;
        int mini = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            profit = max(cost, profit);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input

    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

// another way
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minPrice = 1e9; // initialize minPrice to a large value
        int maxProfit = 0;  // initialize maxProfit to zero

        for (int price : prices)
        { // loop through the prices array
            if (price < minPrice)
            {                     // if the current price is lower than minPrice
                minPrice = price; // update minPrice
            }
            else
            {                                                 // else
                maxProfit = max(maxProfit, price - minPrice); // update maxProfit with the current profit
            }
        }
        return maxProfit; // return the final answer
    }
};
