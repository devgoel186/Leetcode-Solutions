// https://leetcode.com/problems/longest-common-subsequence

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