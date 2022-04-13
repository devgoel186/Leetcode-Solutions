// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0], i = 0;
        
        if(maxReach == nums.size() - 1 || nums.size() == 1)
            return true;
        
        while(i <= maxReach)
        {
            if(nums[i] + i > maxReach)
                maxReach = nums[i] + i;
            else
                i++;
            
            if(maxReach == nums.size() - 1)
                return true;
        }
        
        return false;
    }
};