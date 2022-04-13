// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pmax = 0;
        int min_price = prices[0];
        
        int psum = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            min_price = min(min_price, prices[i]);
            pmax = max(pmax, prices[i] - min_price);
            
            if(pmax > 0)
            {
                psum += pmax;
                pmax = 0;
                min_price = prices[i];
            }
        }
        
        return psum;
    }
};