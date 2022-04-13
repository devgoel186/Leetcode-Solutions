// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1)
            return n;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        int maxEl = 1;
        for(int i = 1; 2 * i <= n; i++)
        {
            dp[2 * i] = dp[i];
            maxEl = max(maxEl, dp[2 * i]);
            if(2 * i < n)
            {
                dp[2 * i + 1] = dp[i] + dp[i + 1];
                maxEl = max(maxEl, dp[2 * i + 1]);
            }            
        }
        
        return maxEl;
    }
};