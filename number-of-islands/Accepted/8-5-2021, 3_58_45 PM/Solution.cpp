// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void check(vector<vector<char>> &grid, int row, int col, int n, int m)
    {   
        if((row < 0 || row >= n) || (col < 0 || col >= m) || (grid[row][col] != '1'))
            return;
        
        vector<pair<int, int>> direction({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
        
        grid[row][col] = '*';
        for(int i = 0; i < 4; i++)
            check(grid, row + direction[i].first, col + direction[i].second, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {                    
                    check(grid, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};