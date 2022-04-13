// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int len = INT_MAX, j = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            while(sum >= target)
            {
                len = min(len, i - j + 1);
                sum -= nums[j];
                j++;
            }
        }
        
        if(len == INT_MAX)
            return 0;
        return len;
    }
};