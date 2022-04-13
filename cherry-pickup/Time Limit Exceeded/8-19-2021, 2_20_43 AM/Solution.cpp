// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
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
};