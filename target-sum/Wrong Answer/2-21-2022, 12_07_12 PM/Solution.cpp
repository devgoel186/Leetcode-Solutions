// https://leetcode.com/problems/target-sum

class Solution {
    private:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int x, int find)
    {
        if(find == 0)
            return 1;
        
        if(x == 0)
            return 0;
        
        if(dp[x][find] != -1)
            return dp[x][find];
        
        if(nums[x - 1] <= find)
            dp[x][find] = helper(nums, dp, x - 1, find - nums[x - 1]) + helper(nums, dp, x - 1, find);
        else
            dp[x][find] = helper(nums, dp, x - 1, find);
        
        return dp[x][find];
    }
    
    public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        int find = (sum + target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int> (find + 1, -1));
        return helper(nums, dp, nums.size(), find);
    }
};