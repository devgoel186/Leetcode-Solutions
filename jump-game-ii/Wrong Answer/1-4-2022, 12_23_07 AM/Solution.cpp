// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int util(vector<int> &nums, int index)
    {
        if(index == nums.size() - 1)
            return 1;
        
        int i = 1, minel = INT_MAX;
        while(index + i < nums.size())
        {
            minel = min(minel, util(nums, index + i));
            i++;
        }
        return minel + 1;
    }
    
    int jump(vector<int>& nums) {
        return util(nums, 0);
    }
};