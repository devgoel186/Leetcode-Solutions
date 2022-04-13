// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dp(n, {INT_MAX, 0});
        
        for(int i = 0; i < n; i++)
        {
            if(grid[0][i] < dp[0].first)
            {
                dp[0] = {grid[0][i], i};
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == dp[i - 1].second)
                    continue;
                
                dp[i] = make_pair(min(dp[i].first, dp[i - 1].first + grid[i][j]), j);
            }
        }
        
        return dp[n - 1].first;
    }
};