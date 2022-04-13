// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    // void helper(vector<vector<int>> &grid, int r, int c)
    // {
    //     if()
    // }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        // dp[0][0] = 0;
        
        
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i == 0 || j == 0) && grid[i][j] != 1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                if(grid[i][j] == 1)
                    dp[i][j] = 0;
                
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};