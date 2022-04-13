// https://leetcode.com/problems/permutations

class Solution {
public:
    void collect(vector<int>& nums, int begin, vector<vector<int>> &res)
    {
        if(begin >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++)
        {
            swap(nums[begin], nums[i]);
            collect(nums, begin + 1, res);
            swap(nums[begin], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        collect(nums, 0, res);
        
        return res;
    }
};