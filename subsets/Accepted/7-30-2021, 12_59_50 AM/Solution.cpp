// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res((1 << nums.size()));
        for(int i = 0; i < (1 << nums.size()); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i & (1 << j))
                {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};