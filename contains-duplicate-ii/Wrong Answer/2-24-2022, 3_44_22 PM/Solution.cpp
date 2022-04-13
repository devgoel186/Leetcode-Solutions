// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < k)
            return false;
        
        for(int i = 0; i < nums.size() - k; i++)
        {
            if(nums[i] == nums[i + k])
                return true;
        }
        
        return false;
    }
};