// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    int subsetSum(vector<vector<int>> &dp, vector<int> &nums, int n, int sum)
    {
        if(n == 0)
            return false;
        
        if(sum == 0)
            return true;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(nums[n - 1] <= sum)
            return dp[n][sum] = subsetSum(dp, nums, n - 1, sum - nums[n - 1]) || subsetSum(dp, nums, n - 1, sum);
        
        else
            return dp[n][sum] = subsetSum(dp, nums, n - 1, sum);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        if(sum % 2 != 0)
            return false;
        
        vector<vector<int>> dp(nums.size() + 1, vector<int> (sum + 1, -1));
        
        return subsetSum(dp, nums, nums.size(), sum / 2);
    }
};