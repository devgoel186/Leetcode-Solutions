// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
    bool isSafe(vector<vector<int>> &grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return false;
        return true;
    }
    
    int helper(vector<vector<int>> &grid, int r, int c)
    {
        if(!isSafe(grid, r, c))
            return 0;
        
        int sum = grid[r][c];
        grid[r][c] = 0;
        
        int w = helper(grid, r, c - 1);
        int x = helper(grid, r - 1, c);
        int y = helper(grid, r, c + 1);
        int z = helper(grid, r + 1, c);
        
        grid[r][c] = sum;
        return sum + max({w, x, y, z});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                res = max(res, helper(grid, i, j));
            }
        }
        
        return res;
    }
};