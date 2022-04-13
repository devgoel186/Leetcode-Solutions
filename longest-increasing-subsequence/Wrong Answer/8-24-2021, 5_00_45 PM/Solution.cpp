// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int helper(vector<int> &nums, int i)
    {
        int sum = 1;
        for(int j = 0; j <= i; j++)
        {
            if(nums[j] < nums[i])
                sum = max(sum, 1 + helper(nums, j));
        }
        
        return sum;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, nums.size() - 1);
    }
};