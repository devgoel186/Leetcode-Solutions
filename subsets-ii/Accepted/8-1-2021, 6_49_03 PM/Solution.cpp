// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++)
        {
            vector<int> f;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    f.push_back(nums[j]);
            }
            
            if(res.size() == 0)
                res.push_back(f);
            
            bool flag = false;
            for(int j = 0; j < res.size(); j++)
            {
                if(res[j] == f)
                {
                    flag = true;
                    break;
                }
            }            
            if(!flag)
                res.push_back(f);
        }
        
        return res;
    }
};