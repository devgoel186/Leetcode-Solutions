// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> dp(n, 0);
        
        int sum = satisfaction[n - 1];
        dp[n - 1] = sum;
        int maxSum = sum;
        
        for(int i = n - 2; i >= 0; i--)
        {            
            dp[i] = satisfaction[i] + dp[i + 1] + sum;
            maxSum = max(maxSum, dp[i]);
            sum = sum + satisfaction[i];
        }
        
        return max(maxSum, 0);
    }
};