// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible

class Solution {
private:
    int MOD = 1e9 + 7;
    
    long long helper(vector<vector<long long>> &dp, int n, int k)
    {
        if(n == 0 || k == 0)
            return 0;
        if(k > n)
            return 0;
        if(k == n)
            return 1;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        dp[n][k] = helper(dp, n - 1, k) * (n - 1) + helper(dp, n - 1, k - 1);
        return dp[n][k] % MOD;
    }
    
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1, -1));
        return helper(dp, n, k);
    }
};