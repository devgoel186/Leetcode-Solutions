// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        int i;
        for(i = 1; i < prices.size(); i++)      
        {       
            if(prices[i] < prices[i - 1])
            {
                profit += (prices[i - 1] - buy);
                buy = prices[i];
            }
        }
        profit += (prices[i - 1] - buy);
        
        return profit;
    }
};