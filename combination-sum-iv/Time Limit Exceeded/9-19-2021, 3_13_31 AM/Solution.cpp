// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    void helper(vector<int>& candidates, int target, int &count)
    {
        if(target < 0)
            return;
        
        if(target == 0)
        {
            count++;
            return;
        }
        
        for(int i = 0; i < candidates.size(); i++)
            helper(candidates, target - candidates[i], count);
    }
    
    int combinationSum4(vector<int>& candidates, int target) {
        // vector<int> temp;
        // vector<vector<int>> res;
        int count = 0;
        helper(candidates, target, count);
        
        return count;
    }
};