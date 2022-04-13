// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int curr = -101;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > curr)
            {
                curr = nums[i];
                swap(nums[i], nums[index]);                
                index++;
            }
        }
        // nums.resize(index, nums.size());
        // nums.shrink_to_fit();
        return index;
    }
};