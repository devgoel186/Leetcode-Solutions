// https://leetcode.com/problems/triangle

class Solution {
public:
    /* O(N*N) - Time and Space
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        
        dp[0][0] = triangle[0][0];
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        
        int minVal = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            minVal = min(minVal, dp[n - 1][i]);
        }
        
        return minVal;
    }
    */
    
    
    /* O(N) - Space */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = triangle[n - 1][i];
        }
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};