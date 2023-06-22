/*  Question:  Best Time to Buy and Sell Stock with Transaction Fee
    Source:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

    CODE:                                                                                       */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;
        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};
