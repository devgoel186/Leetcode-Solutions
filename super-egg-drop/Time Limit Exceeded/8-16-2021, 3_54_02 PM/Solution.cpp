// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int helper(vector<vector<int>> &dp, int n, int k)
    {
        if(dp[n][k] != -1)
            return dp[n][k];
        
        if(n == 0 || n == 1)
        {
            dp[n][k] = n;
            return n;
        }
        
        if(k == 0)
        {
            dp[n][k] = 0;
            return 0;
        }            
        
        if(k == 1)
        {
            dp[n][k] = n;
            return n;
        }
        
        int min = 1e5, res = 0;
        
        for(int i = 1; i <= n; i++)
        {
            res = max(helper(dp, i - 1, k - 1), helper(dp, n - i, k));
            if(res < min)
                min = res;
        }
        
        dp[n][k] = min + 1;
        return dp[n][k];
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(dp, n, k);
    }
};