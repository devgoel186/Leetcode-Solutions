// https://leetcode.com/problems/binary-search

class Solution {
public:
    int helper(vector<int>& nums, int target, int l, int r)
    {
        if(l > r)
            return -1;
        
        int mid = (l + r) / 2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            return helper(nums, target, mid + 1, r);
        return helper(nums, target, l, mid - 1);
    }
    
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
};