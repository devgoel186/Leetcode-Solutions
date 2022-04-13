// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        for(int i = 0; i + 1 < nums.size(); i++)
        {
            if(i & 1)
            {
                if(nums[i] < nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            else
            {
                if(nums[i] > nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
        }
    }
};