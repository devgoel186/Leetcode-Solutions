// https://leetcode.com/problems/knight-dialer

class Solution {
    private:
    int mod = 1e9 + 7;
    
    bool isSafe(int r, int c)
    {
        if(r < 0 || c < 0 || r >= 4 || c >= 3 || (r == 3 && c != 1))
            return false;
        
        return true;
    }
    
    long helper(vector<vector<vector<long>>> &dp, int r, int c, int n)
    {
        if(!isSafe(r, c))
            return 0;
        
        if(n == 1)
            return 1;
        
        if(dp[n][r][c] != -1)
            return dp[n][r][c];
        
        long sum = 0;
        sum += helper(dp, r + 2, c + 1, n - 1) % mod;
        sum += helper(dp, r + 2, c - 1, n - 1) % mod;
        sum += helper(dp, r + 1, c + 2, n - 1) % mod;
        sum += helper(dp, r + 1, c - 2, n - 1) % mod;
        
        sum += helper(dp, r - 2, c + 1, n - 1) % mod;
        sum += helper(dp, r - 2, c - 1, n - 1) % mod;
        sum += helper(dp, r - 1, c + 2, n - 1) % mod;
        sum += helper(dp, r - 1, c - 2, n - 1) % mod;
        
        dp[n][r][c] = sum;
        
        return dp[n][r][c];
    }
    
    public:
    int knightDialer(int n) {
        long count = 0;
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>> (4, vector<long>(3, -1)));
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                count += helper(dp, i, j, n) % mod;
                count %= mod;
            }
        }
        
        return (int)count;
    }
};