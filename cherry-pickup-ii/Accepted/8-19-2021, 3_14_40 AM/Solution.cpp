// https://leetcode.com/problems/cherry-pickup-ii

class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int r, int c1, int c2)
    {
        int n = grid.size(), m = grid[0].size();
        if(r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return false;
        return true;
    }
    
    int dfs(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r, int c1, int c2)
    {
        int n = grid.size(), m = grid[0].size();
        if(!isSafe(grid, r, c1, c2))
            return INT_MIN;
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        if(r == n - 1)
        {
            if(c1 == c2)
                return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }
        
        int cherries = 0;
        if(c1 == c2)
            cherries += grid[r][c1];
        else
            cherries += grid[r][c1] + grid[r][c2];
        
        int ans = 0;
        
        ans = max(cherries + dfs(grid, dp, r + 1, c1 - 1, c2 - 1), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1 - 1, c2), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1 - 1, c2 + 1), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1, c2 - 1), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1, c2), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1, c2 + 1), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1 + 1, c2 - 1), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1 + 1, c2), ans);
        ans = max(cherries + dfs(grid, dp, r + 1, c1 + 1, c2 + 1), ans);
        
        return dp[r][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(75, vector<vector<int>> (n, vector<int> (75, -1)));
        
        return max(dfs(grid, dp, 0, 0, m - 1), 0);
    }
};