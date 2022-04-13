// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    bool isSafe(vector<vector<int>> &matrix, int r, int c, int m, int n)
    {
        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;
        return true;
    }
    
    int helper(vector<vector<int>> &matrix, vector<vector<int>> dp, int m, int n, int r, int c)
    {
        if(dp[r][c] != -1)
            return dp[r][c];
        
        vector<pair<int, int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        int maxPath = 0;
        
        // matrix[i][j]
        
        for(int i = 0; i < 4; i++)
        {
            int x = r + dir[i].first;
            int y = c + dir[i].second;
            
            if(isSafe(matrix, x, y, m, n) && matrix[r][c] < matrix[x][y])
            {
                maxPath = max(maxPath, helper(matrix, dp, m, n, x, y));
            }
        }
        dp[r][c] = maxPath + 1;
        return dp[r][c];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int longestPath = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                longestPath = max(helper(matrix, dp, m, n, i, j), longestPath);
            }
        }
        
        return longestPath;
    }
};