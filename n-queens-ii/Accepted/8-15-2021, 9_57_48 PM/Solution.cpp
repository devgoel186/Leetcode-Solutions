// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    bool isSafe(vector<string> &sol, int r, int c, int n)
    {        
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
    
    void helper(int &num, vector<string> &sol, int r, int n)
    {        
        if(r == n)
        {
            num++;
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isSafe(sol, r, i, n))
            {
                sol[r][i] = 'Q';
                helper(num, sol, r + 1, n);
                sol[r][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int num = 0;
        vector<string> sol(n, string(n, '.'));
        helper(num, sol, 0, n);
        return num;
    }
};