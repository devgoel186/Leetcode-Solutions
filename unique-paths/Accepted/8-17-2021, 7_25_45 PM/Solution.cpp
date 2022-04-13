// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp)
    {    
        int i = 0;
        for(i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[(i & 1)][j] = dp[1 - (i & 1)][j] + dp[(i & 1)][j - 1];
            }
        }
        
        return dp[1 - (i & 1)][n - 1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int> (n, 1));
        return helper(m, n, dp);
    }
};