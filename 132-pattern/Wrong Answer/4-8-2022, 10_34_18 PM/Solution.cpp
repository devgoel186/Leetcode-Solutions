// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            
            while(j < n && k > i && j < k)
            {
                if(nums[i] < nums[k] && nums[k] < nums[j])
                    return true;
                
                else if(nums[i] >= nums[k])
                    k--;
                
                else
                    j++;
            }
        }
        
        return false;
    }
};