// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        
        int max = 0;
        for(int i = index; i < nums.size(); i++)
        {
            if(abs(nums[i]) - 1 < nums.size())
            {
                nums[abs(nums[i]) - 1] *= -1;
                if(abs(nums[i]) > max)
                    max = abs(nums[i]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                return i + 1;
        }
        
        return max + 1;
    }
};