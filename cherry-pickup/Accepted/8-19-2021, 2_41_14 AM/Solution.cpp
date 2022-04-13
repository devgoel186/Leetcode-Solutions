// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
    /* DP SOLUTION */
    
    bool isSafe(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
    {
        int n = grid.size();
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || (grid[r1][c1] == -1) || (grid[r2][c2] == -1))
            return false;
        return true;
    }
    
    int dfs(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int r1, int c1, int r2)
    {
        int c2 = r1 + c1 - r2;
        int n = grid.size();
        
        if(!isSafe(grid, r1, c1, r2, c2))
            return INT_MIN;
        
        if(r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];
        
        int a = dfs(dp, grid, r1 + 1, c1, r2 + 1);
        int b = dfs(dp, grid, r1, c1 + 1, r2 + 1);
        int c = dfs(dp, grid, r1 + 1, c1, r2);
        int d = dfs(dp, grid, r1, c1 + 1, r2);
        
        cherries += max({a, b, c, d});
        
        return dp[r1][c1][r2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return max(dfs(dp, grid, 0, 0, 0), 0);
    }
    
    /* BACKTRACKING SOLUTION
    
    int maxCherries = INT_MIN;
    
    bool isSafe(vector<vector<int>> &grid, int r, int c)
    {
        int n = grid.size();
        if(r < 0 || r >= n || c < 0 || c >= n || (grid[r][c] == -1))
            return false;
        return true;
    }
    
    void dfsBack(vector<vector<int>> &grid, int r, int c, int count)
    {
        int n = grid.size();
        
        if(!isSafe(grid, r, c))
            return;
        
        int cherries = grid[r][c];
        grid[r][c] = 0;        
        
        if(r == 0 && c == 0)
        {
            maxCherries = max(count + cherries, maxCherries);
            return;
        }        
        
        dfsBack(grid, r - 1, c, count + cherries);
        dfsBack(grid, r, c - 1, count + cherries);
        
        grid[r][c] = cherries;
    }
    
    void dfsFront(vector<vector<int>> &grid, int r, int c, int count)
    {
        int n = grid.size();
        
        if(!isSafe(grid, r, c))
            return;
        
        int cherries = grid[r][c];
        grid[r][c] = 0;
        
        if(r == n - 1 && c == n - 1)
            dfsBack(grid, r, c, count + cherries);
        
        dfsFront(grid, r + 1, c, count + cherries);
        dfsFront(grid, r, c + 1, count + cherries);
        
        grid[r][c] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        dfsFront(grid, 0, 0, 0);
        if(maxCherries == INT_MIN)
            return 0;
        return maxCherries;
    }
    
    */
};