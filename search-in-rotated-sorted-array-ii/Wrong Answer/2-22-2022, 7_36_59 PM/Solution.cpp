// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
    private:
    bool binarySearch(vector<int> &nums, int i, int j, int target)
    {   
        if(i > j)
            return false;
        
        int mid = (i + j) / 2;
        
        if(nums[mid] == target)
            return true;
        
        if(nums[i] == nums[mid] && nums[j] == nums[mid])
            return binarySearch(nums, i + 1, j - 1, target);   
        
        if(nums[i] > nums[j] && nums[mid] < target)
            return binarySearch(nums, i, mid - 1, target);
        if(nums[i] > nums[j] && nums[mid] > target)
            return binarySearch(nums, mid + 1, j, target);
        
        if(nums[i] < nums[j] && nums[mid] > target)
            return binarySearch(nums, mid + 1, j, target);
        if(nums[i] < nums[j] && nums[mid] < target)
            return binarySearch(nums, i, mid - 1, target);
        
        return false;
    }
    
    public:
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};