// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int helper(vector<int> &nums, vector<int> &dp, int i)
    {
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], 1 + helper(nums, dp, j));
        }
        
        return dp[i];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int maxVal = 0;
        for(int i = 0; i < nums.size(); i++)
            maxVal = max(helper(nums, dp, i), maxVal);
        
        return maxVal;
    }
};