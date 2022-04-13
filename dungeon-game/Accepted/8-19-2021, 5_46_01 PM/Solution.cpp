// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    // bool isSafe(vector<vector<int>> &grid, int r, int c)
    // {
    //     int n = grid.size();
    //     if(r < 0 || r >= n || c < 0 || c >= n)
    //         return false;
    //     return true;
    // }
    
    int game(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(n == 0)
            return 0;
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));
        dp[n - 1][m] = 1;
        dp[n][m - 1] = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                dp[i][j] = max((min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]), 1);
            }
        }
        
        return dp[0][0];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return game(dungeon);
    }
};