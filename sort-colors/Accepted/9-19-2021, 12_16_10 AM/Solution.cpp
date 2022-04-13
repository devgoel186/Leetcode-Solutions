// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, low = 0, high = n - 1;
        while(i <= high)
        {
            if(nums[i] == 0)
                swap(nums[low++], nums[i++]);
            else if(nums[i] == 2)
                swap(nums[high--], nums[i]);
            else
                i++;
        }
    }
};