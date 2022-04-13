// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        dp[0][1] = 1;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {   
                if(grid[i - 1][j - 1] == 1)
                    continue;
                
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m][n];
    }
};