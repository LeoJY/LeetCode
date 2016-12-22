//123. Best Time to Buy and Sell Stock III
//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for (int i = 0; i < n; i++){
        	buy1 = max(buy1, -prices[i]);
        	sell1 = max(sell1, buy1 + prices[i]);
        	buy2 = max(buy2, sell1 - prices[i]);
        	sell2 = max(sell2, buy2 + prices[i]);
        }
        return max(sell1, sell2);
    }
}; 

