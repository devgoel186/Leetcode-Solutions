// https://leetcode.com/problems/stone-game

class Solution {
public:
    int helper(vector<int> &piles, vector<vector<int>> &dp, int i, int j)
    {
        if(i == j - 1)
            return max(piles[i], piles[j - 1]);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int pickLeft = piles[i] + max(helper(piles, dp, i + 2, j), helper(piles, dp, i + 1, j - 1));    
        int pickRight = piles[j] + max(helper(piles, dp, i + 1, j - 1), helper(piles, dp, i, j - 2));
        
        return dp[i][j] = max(pickLeft, pickRight);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        int i = 0, j = n - 1;
        int ans = helper(piles, dp, i, j);
        return ans;
    }
};