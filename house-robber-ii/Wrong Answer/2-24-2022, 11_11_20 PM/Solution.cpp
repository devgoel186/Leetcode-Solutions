// https://leetcode.com/problems/house-robber-ii

class Solution {
    public:
    int helper(vector<int> &nums, vector<int> &dp, int lim, int i)
    {
        if(i <= lim)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = max(helper(nums, dp, lim, i - 2) + nums[i - 1], helper(nums, dp, lim, i - 1));
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> dp(n + 1, -1);
        
        int a = helper(nums, dp, 0, n - 1);
        int b = helper(nums, dp, 1, n);
        
        return max(a, b);
    }
};