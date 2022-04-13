// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int findPivot(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return -1;
        if(l == r)
            return l; 
        int mid = (l + r) / 2;
        if(mid < r && nums[mid] > nums[mid + 1])
            return mid;
        if(mid > l && nums[mid] < nums[mid - 1])
            return mid - 1;
        if(nums[l] >= nums[mid])
            return findPivot(nums, l, mid - 1);
        return findPivot(nums, mid + 1, r);
    }
    
    int helper(vector<int>& nums, int target, int l, int r)
    {
        if(l > r)
            return -1;
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return helper(nums, target, l, mid - 1);
        return helper(nums, target, mid + 1, r);
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size() - 1);
        if(pivot == -1)
            return helper(nums, target, 0, nums.size() - 1);
        if(nums[pivot] == target)
            return pivot;
        if(nums[0] <= target)
            return helper(nums, target, 0, pivot - 1);
        return helper(nums, target, pivot + 1, nums.size() - 1);
    }
};