// https://leetcode.com/problems/burst-balloons

class Solution {
    private:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int i, int j)
    {
        if(i >= j)
            return 0;
        
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        dp[i][j] = 0;
        for(int k = i; k < j; k++)
        {
            dp[i][j] = max(dp[i][j], helper(nums, dp, i, k) + helper(nums, dp, k + 1, j) + nums[i - 1] * nums[k] * nums[j]);
        }
        
        return dp[i][j];
    }
    
    public:
    int maxCoins(vector<int>& num) {
        int n = num.size();
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, INT_MIN));
        
        vector<int> nums;
        nums.push_back(1);
        for(auto i : num)
            nums.push_back(i);
        nums.push_back(1);

        return helper(nums, dp, 1, n + 1);
    }
};