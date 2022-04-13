// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int helper(vector<vector<int>> &dp, int k, int n)
    {
        if(dp[k][n] != 0)
            return dp[k][n];
        
        if(n <= 1)
            return 1;
        
        if(k == 1)
            return n;
        
        int min = 1e5, res = 0;
        
        for(int i = 1; i <= n; i++)
        {
            res = max(helper(dp, k - 1, i - 1), helper(dp, k, n - i)) + 1;
            if(res < min)
                min = res;
        }
        
        dp[k][n] = min;
        return dp[k][n];
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        return helper(dp, k, n);
    }
};