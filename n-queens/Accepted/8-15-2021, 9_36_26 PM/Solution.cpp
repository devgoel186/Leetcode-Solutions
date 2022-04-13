// https://leetcode.com/problems/n-queens

class Solution {
public:
    bool isSafe(vector<string> &sol, int r, int c, int n)
    {
        // if(r < 0 || c < 0 || r >= n || c >= n)
        //     return false;
        
        for(int i = 0; i < n; i++)
        {
            if(sol[i][c] == 'Q')
                return false;
        }
        
        int i = r - 1, j = c - 1;
        while(i >= 0 && j >= 0)
        {
            if(sol[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = r - 1, j = c + 1;
        while(i >= 0 && j < n)
        {
            if(sol[i][j] == 'Q')
               return false;
            i--;
            j++;
        }
        
        return true;
    }
    
    void helper(vector<vector<string>> &dp, vector<string> &sol, int r, int n)
    {        
        if(r == n)
        {
            dp.push_back(sol);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isSafe(sol, r, i, n))
            {
                sol[r][i] = 'Q';
                helper(dp, sol, r + 1, n);
                    // return true;
                sol[r][i] = '.';
            }
        }
        
        // return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> dp;
        vector<string> sol(n, string(n, '.'));
        helper(dp, sol, 0, n);
        return dp;
    }
};