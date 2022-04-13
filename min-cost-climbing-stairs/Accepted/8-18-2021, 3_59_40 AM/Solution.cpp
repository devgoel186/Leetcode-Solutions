// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        int i = 0;
        for(i = 2; i < cost.size(); i++)
        {
            dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
        }
        
        return min(dp[i - 1], dp[i - 2]);
    }
};