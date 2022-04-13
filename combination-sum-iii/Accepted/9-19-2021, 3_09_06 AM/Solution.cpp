// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    void helper(vector<int> &temp, vector<vector<int>> &res, int k, int n, int begin)
    {
        if(n < 0)
            return;
        
        if(n == 0 && k == 0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i = begin; i <= 9; i++)
        {
            temp.push_back(i);
            helper(temp, res, k - 1, n - i, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(temp, res, k, n, 1);
        
        return res;
    }
};