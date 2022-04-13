// https://leetcode.com/problems/combinations

class Solution {
public:
    void helper(int n, int k, int i, vector<vector<int>> &res, vector<int> &ans)
    {
        if(ans.size() == k)
        {
            res.push_back(ans);
            return;
        }
        
        for(int j = i + 1; j <= n; j++)
        {
            ans.push_back(j);
            helper(n, k, j, res, ans);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for(int i = 1; i <= n; i++)
        {
            vector<int> ans;
            ans.push_back(i);
            helper(n, k, i, res, ans);
        }
        
        return res;
    }
};