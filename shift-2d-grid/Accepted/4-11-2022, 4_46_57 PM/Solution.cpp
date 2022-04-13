// https://leetcode.com/problems/shift-2d-grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0)
            return grid;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        
        for(int i = 0; i < n - 1; i++)
            for(int j = 0; j < m; j++)
                ans[j][i + 1] = grid[j][i];
        
        for(int i = 0; i < m; i++)
            ans[(i + 1) % m][0] = grid[i][n - 1];
        
        return shiftGrid(ans, k - 1);
    }
};