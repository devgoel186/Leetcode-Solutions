// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p1 = prices[0], p2 = prices[prices.size() - 1];
        
        vector<int> pre(prices.size(), 0), post(prices.size(), 0);
        
        for(int i = 1; i < prices.size(); i++)
        {
            pre[i] = max(pre[i - 1], prices[i] - p1);
            p1 = min(p1, prices[i]);
            
            int j = prices.size() - 1 - i;
            post[j] = max(post[j + 1], p2 - prices[j]);
            p2 = max(p2, prices[j]);
        }
        
        int res = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            pre[i] += post[i];
            res = max(res, pre[i]);
        }
        
        return res;
    }
};