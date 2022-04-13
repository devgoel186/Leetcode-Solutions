// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {        
        for(int i = 1; i < grid.size(); i++)
            grid[i][0] += grid[i - 1][0];
        for(int i = 1; i < grid[0].size(); i++)
            grid[0][i] += grid[0][i - 1];
        
        int i = 1, j = 1;
        
        while(i < grid.size())
        {            
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            j++;
            if(j == grid[0].size())
            {
                i++;
                j = 1;
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};