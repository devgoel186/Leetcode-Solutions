// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int helper(vector<int> &nums, int index)
    {
        int a = 0;
        int b = 0, c = 0, n = nums.size();
        for(int i = index; i < n - (1 - index); i++)
        {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        
        return c;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0), helper(nums, 1));
    }
};