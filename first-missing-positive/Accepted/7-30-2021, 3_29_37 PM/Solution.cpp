// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int segregate(vector<int> &nums)
    {
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        nums = vector<int>(nums.begin() + index, nums.end());
        return index;
    }
    
    int firstMissingPositiveUtil(vector<int>& nums) {        
        int max = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(abs(nums[i]) - 1 < nums.size() && nums[abs(nums[i]) - 1] > 0)
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
    
    int firstMissingPositive(vector<int>& nums) {
        int x = segregate(nums);
        return firstMissingPositiveUtil(nums);
    }
};