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
                swap(nums[i], nums[index]);
                curr = nums[i];
                index++;
            }
        }
        return index + 1;
    }
};