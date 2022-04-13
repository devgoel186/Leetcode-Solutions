// https://leetcode.com/problems/spiral-matrix

class Solution {
    private:
    bool check(int a, int b, int m, int n)
    {
        if(a >= m || b >= n)
            return true;
        return false;
    }
    
    void helper(vector<vector<int>> &matrix, int a, int b, int m, int n, vector<int> &res)
    {
        if(check(a, b, m, n))
            return;
        
        for(int i = b; i < n; i++)
        {
            res.push_back(matrix[a][i]);
        }
        a++;
        if(check(a, b, m, n))
            return;
        
        for(int i = a; i < m; i++)
        {
            res.push_back(matrix[i][n - 1]);
        }
        n--;
        if(check(a, b, m, n))
            return;
        
        for(int i = n - 1; i >= b; i--)
        {
            res.push_back(matrix[m - 1][i]);
        }
        m--;
        if(check(a, b, m, n))
            return;
        
        for(int i = m - 1; i >= a; i--)
        {
            res.push_back(matrix[i][b]);
        }
        b++;
        if(check(a, b, m, n))
            return;
        
        helper(matrix, a, b, m, n, res);
    }
    
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        helper(matrix, 0, 0, matrix.size(), matrix[0].size(), res);
        
        return res;
    }
};