// https://leetcode.com/problems/jump-game-ii

class Solution {
    private:
    int helper(vector<int> &nums, vector<int> &dp, int i)
    {
        if(i == 0)
            return 0;
        
        if(dp[i] != INT_MAX)
            return dp[i];
        
        for(int j = i - 1; j >= 0; j--)
        {
            if(j + nums[j] < i)
                continue;
                
            dp[i] = 1 + min(helper(nums, dp, j), dp[i]);
        }
        
        return dp[i];
    }
        
    public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        return helper(nums, dp, n - 1);
    }
};