// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int r, int c)
    {
        int n = matrix.size();
        
        if(c < 0 || c >= n)
            return INT_MAX;
        
        if(r == n - 1)
            return matrix[r][c];
        
        if(dp[r][c] != INT_MAX)
            return dp[r][c];
        
        dp[r][c] = min({helper(matrix, dp, r + 1, c - 1), helper(matrix, dp, r + 1, c), helper(matrix, dp, r + 1, c + 1)}) + matrix[r][c];
        
        return dp[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        
        int maxVal = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            maxVal = min(maxVal, helper(matrix, dp, 0, i));
        }

        return maxVal;
    }
};