// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    bool isSafe(vector<vector<int>> &matrix, int r, int c, int m, int n)
    {
        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;
        return true;
    }
    
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n, int r, int c)
    {
        if(dp[r][c] != -1)
            return dp[r][c];
        
        vector<pair<int, int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        
        for(int i = 0; i < 4; i++)
        {
            int x = r + dir[i].first;
            int y = c + dir[i].second;
            
            if(isSafe(matrix, x, y, m, n) && matrix[r][c] < matrix[x][y])
            {
                dp[r][c] = max(dp[r][c], 1 + helper(matrix, dp, m, n, x, y));
            }
        }
        
        
        dp[r][c] = max(dp[r][c], 1);
        
        return dp[r][c];
    }
    
//     int dfs(vector<vector<int>> m, vector<vector<int>> dp, int i, int j){
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(i-1 >= 0 && m[i-1][j] > m[i][j]){
//             dp[i][j] = max(dp[i][j], 1+dfs(m, dp, i-1, j));
//         }
//         if(j-1 >= 0 && m[i][j-1] > m[i][j]){
//             dp[i][j] = max(dp[i][j], 1+dfs(m, dp, i, j-1));
//         }
//         if(i+1 < m.size() && m[i+1][j] > m[i][j]){
//             dp[i][j] = max(dp[i][j], 1+dfs(i+1, j));
//         }
//         if(j+1 < m[0].size() && m[i][j+1] > m[i][j]){
//             dp[i][j] = max(dp[i][j], 1+dfs(i, j+1));
//         }
//         dp[i][j] = max(dp[i][j], 1);
        
//         return dp[i][j];
//     }
    
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