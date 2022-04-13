// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        if(nums.empty())
            return 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[index] == val && nums[index] != nums[i + 1])
            {
                swap(nums[index], nums[i + 1]);
                index++;
            }
            else if(nums[index] != val)
                index++;
        }
        return index;
    }
};