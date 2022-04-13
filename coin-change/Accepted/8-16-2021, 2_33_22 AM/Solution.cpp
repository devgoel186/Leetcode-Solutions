// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
        
        if(dp[amount] == 1e9)
            return -1;
        return dp[amount];
    }
};