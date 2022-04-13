// https://leetcode.com/problems/longest-common-subsequence

// class Solution {
// public:
//     int helper(string text1, string text2, int i, int j, vector<vector<int>> &dp)
//     {
//         if(i == 0 || j == 0)
//             return 0;
        
//         if(dp[i - 1][j - 1] != -1)
//             return dp[i - 1][j - 1];
        
//         if(text1[i - 1] == text2[j - 1])
//             dp[i - 1][j - 1] = 1 + helper(text1, text2, i - 1, j - 1, dp);
//         else
//             dp[i - 1][j - 1] = max(helper(text1, text2, i - 1, j, dp), helper(text1, text2, i, j - 1, dp));
        
//         return dp[i - 1][j - 1];
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length(), n = text2.length();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
        
//         return helper(text1, text2, m, n, dp);
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> lcs(2, vector<int> (m + 1, 0));
        
        int i;
        for(i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                    lcs[i & 1][j] = 1 + lcs[(i - 1) & 1][j - 1];
                else
                    lcs[i & 1][j] = max(lcs[(i - 1) & 1][j], lcs[i & 1][j - 1]);
            }
        }
        
        return lcs[(i - 1) & 1][m];
    }
};