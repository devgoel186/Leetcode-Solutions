// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double> (query_glass + 2, 0));
        dp[0][0] = poured;
        
        for(int i = 0; i < query_row; i++)
        {
            for(int j = 0; j <= query_glass; j++)
            {
                double leak = max(0.0, (dp[i][j] - 1) / 2);
                dp[i + 1][j] += leak;
                dp[i + 1][j + 1] += leak;
            }
        }
        
        return min(dp[query_row][query_glass], 1.0);
    }
};