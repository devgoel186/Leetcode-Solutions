// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    bool isSafe(const vector<vector<int>> &grid, int row, int col, int n, int m)
    {
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] < 0)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>> &grid, int &count, int visited, int nonObstacles, int row, int col, int n, int m)
    {
        if(!isSafe(grid, row, col, n, m))
            return;
        
        visited++;
        
        if(grid[row][col] == 2 && visited == nonObstacles)
        {
            count++;
            return;
        }
        
        if(grid[row][col] == 2)
            return;
        
        grid[row][col] = -1;
        
        // cout << visited << " ";
        
        vector<pair<int, int>> dir({{0, -1}, {-1, 0}, {0, 1}, {1, 0}});
        
        for(int i = 0; i < 4; i++)
        {
            dfs(grid, count, visited, nonObstacles, row + dir[i].first, col + dir[i].second, n, m);
        }
        
        grid[row][col] = 0;
        visited--;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int nonObstacles = 0, res = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != -1)
                    nonObstacles++;
            }
        }
        
        // cout << nonObstacles << " ";
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    dfs(grid, res, 0, nonObstacles, i, j, n, m);
            }
        }
        
        return res;
    }
};