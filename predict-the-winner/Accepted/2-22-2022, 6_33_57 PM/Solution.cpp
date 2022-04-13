// https://leetcode.com/problems/predict-the-winner

class Solution {
    private:
    int helper(vector<vector<int>> &dp, vector<int> &nums, int i, int j)
    {
        if(i > j)
            return 0;
            
        if(i == j)
            return nums[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int a = nums[i] + min(helper(dp, nums, i + 1, j - 1), helper(dp, nums, i + 2, j));
        int b = nums[j] + min(helper(dp, nums, i + 1, j - 1), helper(dp, nums, i, j - 2));
        
        dp[i][j] = max(a, b);
        
        return dp[i][j];
    }
    
    public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(auto i : nums)
            sum += i;
            
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int x = helper(dp, nums, 0, n - 1);
        
        if(x >= ((sum + 1) / 2))
            return true;
        return false;
    }
};