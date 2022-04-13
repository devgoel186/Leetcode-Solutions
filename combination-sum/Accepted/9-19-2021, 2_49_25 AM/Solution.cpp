// https://leetcode.com/problems/combination-sum

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
            temp.push_back(candidates[i]);
            helper(i, sum + candidates[i], candidates, target, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(0, 0, candidates, target, temp, res);
        
        return res;
    }
};