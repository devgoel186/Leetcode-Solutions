// https://leetcode.com/problems/coin-change

class Solution {
    public:
    int helper(vector<vector<int>> &dp, vector<int> &coins, int n, int amount)
    {
        if(amount == 0)
            return 0;
        
        if(n == 0)
            return INT_MAX - 1;
        
        if(dp[n][amount] != INT_MAX)
            return dp[n][amount];
        
        if(coins[n - 1] <= amount)
            dp[n][amount] = min(1 + helper(dp, coins, n, amount - coins[n - 1]), helper(dp, coins, n - 1, amount));
        else
            dp[n][amount] = helper(dp, coins, n - 1, amount);
        
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, INT_MAX));
        
        int ans = helper(dp, coins, n, amount);
        if(ans == INT_MAX - 1)
            return -1;
        
        return ans;
    }
};