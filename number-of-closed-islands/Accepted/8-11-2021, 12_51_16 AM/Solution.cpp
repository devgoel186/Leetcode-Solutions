// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:
    void check(vector<vector<int>> &grid, int row, int col, int n, int m)
    {   
        if((row < 0 || row >= n) || (col < 0 || col >= m) || (grid[row][col] != 0))
            return;
        
        vector<pair<int, int>> direction({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
        
        grid[row][col] = 2;
        for(int i = 0; i < 4; i++)
            check(grid, row + direction[i].first, col + direction[i].second, n, m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 0)
                check(grid, i, 0, n, m);
            if(grid[i][m - 1] == 0)
                check(grid, i, m - 1, n, m);
        }
        
        for(int i = 1; i < m - 1; i++)
        {
            if(grid[0][i] == 0)
                check(grid, 0, i, n, m);
            if(grid[n - 1][i] == 0)
                check(grid, n - 1, i, n, m);
        }
        
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < m - 1; j++)
            {
                if(grid[i][j] == 0)
                {                    
                    check(grid, i, j, n, m);
                    count++;
                }
            }
        }
        return count;    
    }
};