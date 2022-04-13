// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int helper(vector<int>& candidates, int target, vector<int> &dp)
    {
        if(dp[target] != -1)
            return dp[target];
        
        int ways = 0;
        for(int i = 0; i < candidates.size(); i++)
        {
            if(target >= candidates[i])
                ways += helper(candidates, target - candidates[i], dp);
        }
        
        return dp[target] = ways;
    }
    
    int combinationSum4(vector<int>& candidates, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        
        helper(candidates, target, dp);
        
        return dp[target];
    }
};