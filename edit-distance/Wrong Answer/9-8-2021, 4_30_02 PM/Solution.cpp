// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(2, vector<int> (m + 1, 0));
        
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
        
        // dp[1][0] = 1;
        
        int i;
        for(i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i & 1][j] = dp[1 - (i & 1)][j - 1];
                else
                {
                    int a = dp[1 - (i & 1)][j];
                    int b = dp[i & 1][j - 1];
                    int c = dp[1 - (i & 1)][j - 1];
                    dp[i & 1][j] = min({a, b, c}) + 1;
                }
            }
        }
        
        return dp[(i - 1) & 1][m] + 1;
    }
};