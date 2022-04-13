// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            currMin = min(currMin, prices[i]);
            maxProfit = max(maxProfit, prices[i] - currMin);
        }
        
        return maxProfit;
    }
};