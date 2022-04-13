// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
    public:
    vector<int> getRow(int r) {
        vector<vector<int>> dp(r + 1, vector<int> (r + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i <= r; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        
        return dp[r];
    }
};