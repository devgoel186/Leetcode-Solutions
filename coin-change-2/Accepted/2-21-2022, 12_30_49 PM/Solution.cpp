// https://leetcode.com/problems/coin-change-2

class Solution {
    private:
    int helper(vector<vector<int>> &dp, vector<int> &coins, int i, int sum)
    {
        if(sum == 0)
            return 1;
        if(i == 0)
            return 0;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        if(coins[i - 1] <= sum)
            dp[i][sum] = helper(dp, coins, i, sum - coins[i - 1]) + helper(dp, coins, i - 1, sum);
        else
            dp[i][sum] = helper(dp, coins, i - 1, sum);
        
        return dp[i][sum];
    }
    
    public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        
        return helper(dp, coins, coins.size(), amount);
    }
};