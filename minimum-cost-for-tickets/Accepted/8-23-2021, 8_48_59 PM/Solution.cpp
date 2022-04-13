// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int helper(vector<int> &travel, vector<int> &days, vector<int> &costs, vector<int> &dp, int i)
    {
        if(i > 365)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(travel[i] == 0)
            return dp[i] = helper(travel, days, costs, dp, i + 1);

        
        dp[i] = min({helper(travel, days, costs, dp, i + 1) + costs[0], helper(travel, days, costs, dp, i + 7) + costs[1], helper(travel, days, costs, dp, i + 30) + costs[2]});
        return dp[i];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> travel(366, 0);
        vector<int> dp(366, -1);
        for(int i = 0; i < days.size(); i++)
        {
            travel[days[i]]++;
        }
        
        return helper(travel, days, costs, dp, 1);
    }
};