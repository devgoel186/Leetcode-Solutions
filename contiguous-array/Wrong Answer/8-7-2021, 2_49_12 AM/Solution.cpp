// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        unordered_map<int, int> m;
        m[0] = -1;
        int maxSub = 0;
        int sum = (nums[0] == 0) ? -1 : 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            sum = (nums[i] == 0) ? sum - 1 : sum + 1;
            
            if(m.find(sum) == m.end())
                m[sum] = i;
            
            if(i - m[sum] > maxSub)
            {
                maxSub = i - m[sum];
                m[sum] = i;
            }
        }
        
        return maxSub;
    }
};