// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count == (sum - nums[i]) / 2)
                return i;
            
            else 
                count += nums[i];
        }
        
        return -1;
    }
};