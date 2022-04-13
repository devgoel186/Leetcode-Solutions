// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int a = 0, b = nums[0], c = b;
        for(int i = 2; i <= nums.size(); i++)
        {
            c = max(b, a + nums[i - 1]);
            a = b;
            b = c;
        }
        return c;
    }
};