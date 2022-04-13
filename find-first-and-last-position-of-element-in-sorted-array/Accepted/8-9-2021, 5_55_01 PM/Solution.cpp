// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int search(vector<int> &nums, int target, int l, int r)
    {
        if(l > r)
            return -1;
        int mid = (l + r) / 2;
        if(nums[mid] > target)
            return search(nums, target, l, mid - 1);
        if(nums[mid] < target)
            return search(nums, target, mid + 1, r);
        return mid;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = search(nums, target, 0, nums.size() - 1);
        int left = x - 1, right = x + 1;
        while(left >= 0)
        {
            if(nums[left] == target)
                left--;
            else
                break;
        }
        while(right < nums.size())
        {
            if(nums[right] == target)
                right++;
            else
                break;
        }
        
        return {left + 1, right - 1};
    }
};