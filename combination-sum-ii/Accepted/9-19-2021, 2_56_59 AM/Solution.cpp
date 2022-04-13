// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void helper(int begin, int sum, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(sum > target)
            return;
        
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = begin; i < candidates.size(); i++)
        {
            if(i != begin && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            helper(i + 1, sum + candidates[i], candidates, target, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        helper(0, 0, candidates, target, temp, res);
        
        return res;
    }
};