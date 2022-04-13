// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
    private:
    int helper(string x, string y, vector<vector<int>> &dp, int m, int n)
    {
        if(m > n)
            return 0;
        
        if(m == n)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(x[m - 1] == y[n - 1])
            dp[m][n] = 2 + helper(x, y, dp, m + 1, n - 1);
        else
            dp[m][n] = max(helper(x, y, dp, m + 1, n), helper(x, y, dp, m, n - 1));
        
        return dp[m][n];
    }
    
    public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return helper(s, s, dp, 1, n);
    }
};