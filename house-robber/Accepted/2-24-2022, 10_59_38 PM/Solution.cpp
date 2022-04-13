// https://leetcode.com/problems/house-robber

class Solution {
    public:
    int helper(vector<int> &nums, vector<int> &dp, int i)
    {
        if(i <= 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = max(helper(nums, dp, i - 2) + nums[i - 1], helper(nums, dp, i - 1));
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        
        return helper(nums, dp, n);
    }
};