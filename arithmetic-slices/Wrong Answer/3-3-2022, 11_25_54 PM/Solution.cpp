// https://leetcode.com/problems/arithmetic-slices

class Solution {
    public:
    int helper(vector<int> &dp, vector<int> &nums, int i)
    {   
        if(i < 2)
            return 0;
        
        if(dp[i] != 0)
            return dp[i];
        
        if(nums[i] - nums[i-1] == nums[i - 1] - nums[i - 2])
            dp[i] = helper(dp, nums, i - 1) + 1;
        else
            dp[i] = helper(dp, nums, i - 1);
        
        return dp[i];    
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        vector<int> dp(n, 0);
        helper(dp, nums, n - 1);
        
        int res = 0;
        for(auto i : dp)
            res += i;
        
        return res;
    }
};