// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int findPivot(vector<int> &nums, int l, int r)
    {
        if(l == r)
            return l; 
        int mid = (l + r) / 2;
        if(nums[mid] > nums[mid + 1] && mid < r)
            return mid;
        if(nums[mid] < nums[mid - 1] && mid > l)
            return mid - 1;
        if(nums[l] >= nums[r])
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
        int x = helper(nums, target, 0, pivot);
        int y = helper(nums, target, pivot + 1, nums.size() - 1);
        if(x == -1)
            return y;
        return x;
    }
};