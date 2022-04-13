// https://leetcode.com/problems/maximum-product-subarray

class Solution {
    public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int res = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            if(l > 0)
                l *= nums[i];
            else
                l = nums[i];
            
            if(r > 0)
                r *= nums[n - 1 - i];
            else
                r = nums[n - 1 - i];
            
            res = max({res, l, r});
        }
        
        return res;
    }
};