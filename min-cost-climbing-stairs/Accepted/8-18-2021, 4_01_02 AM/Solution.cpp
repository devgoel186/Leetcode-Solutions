// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        int a = cost[0];
        int b = cost[1];
        
        int i = 0;
        for(i = 2; i < cost.size(); i++)
        {
            dp[i] = cost[i] + min(a, b);
            a = b;
            b = dp[i];
        }
        
        return min(a, b);
    }
};