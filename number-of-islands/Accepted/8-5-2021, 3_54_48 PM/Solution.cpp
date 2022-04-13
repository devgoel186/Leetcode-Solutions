// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void check(vector<vector<char>> &grid, int row, int col)
    {
        cout << row << " " << col;
        
        if((row < 0 || row >= grid.size()) || (col < 0 || col >= grid[row].size()))
            return;
        
        if(grid[row][col] == '0')
            return;
        
        vector<pair<int, int>> direction({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
        if(grid[row][col] == '1')
        {
            grid[row][col] = '*';
            for(int i = 0; i < 4; i++)
                check(grid, row + direction[i].first, col + direction[i].second);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {                    
                    check(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};