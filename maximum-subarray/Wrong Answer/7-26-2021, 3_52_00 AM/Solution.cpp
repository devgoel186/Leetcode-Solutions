// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        int prevMax = max;
        for(int i = 0; i < nums.size(); i++)   
        {
            max = nums[i] + max;
            if(max < 0)
                max = 0;
            if(max > prevMax)
                prevMax = max;
        }
        return prevMax;
    }
};