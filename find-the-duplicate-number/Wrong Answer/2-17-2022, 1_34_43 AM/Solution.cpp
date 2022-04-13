// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i <= n; i++)
        {
            if(nums[i] < 0)
                continue;
            nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        }
        
        for(int i = 0; i <= n; i++)
        {
            if(nums[i] > 0)
                return i + 1;
        }
        
        return -1;
    }
};