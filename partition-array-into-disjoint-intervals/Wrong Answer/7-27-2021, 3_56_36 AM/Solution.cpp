// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int max = nums[0];
        int max2 = nums[0];
        int l = 0;
        int r = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < max && max2 > max)
            {
                l++;
                max2 = max;
            }
            if(nums[i] < max)
            {
                l++;
            }
            else if(nums[i] >= max)
            {
                max2 = nums[i];
                r++;
            }
        }
        return l + r - 1; 
    }
};