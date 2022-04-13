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
            int x = sum - nums[i];
            if((count == x / 2) && x % 2 == 0)
                return i;
            
            else 
                count += nums[i];
        }
        
        return -1;
    }
};