// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
    private:
    int lcs(string x, string y, vector<vector<int>> &dp, int m, int n)
    {
        if(m == 0 || n == 0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(x[m - 1] == y[n - 1])
            dp[m][n] = 1 + lcs(x, y, dp, m - 1, n - 1);
        else
            dp[m][n] = max(lcs(x, y, dp, m - 1, n), lcs(x, y, dp, m, n - 1));
        
        return dp[m][n];
    }
    
    public:
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return lcs(x, s, dp, n, n);
    }
};