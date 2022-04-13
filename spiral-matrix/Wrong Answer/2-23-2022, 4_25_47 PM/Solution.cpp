// https://leetcode.com/problems/spiral-matrix

class Solution {
    private:
    void helper(vector<vector<int>> &matrix, int a, int b, int m, int n, vector<int> &res)
    {
        if(a >= m || b >= n)
            return;
        
        for(int i = b; i < n; i++)
            res.push_back(matrix[a][i]);
        
        for(int i = a + 1; i < m; i++)
            res.push_back(matrix[i][n - b - 1]);
        
        for(int i = n - b - 2; i >= b; i--)
            res.push_back(matrix[m - a - 1][i]);
        
        for(int i = m - a - 2; i > a; i--)
            res.push_back(matrix[i][b]);
        
        helper(matrix, a + 1, b + 1, m - 1, n - 1, res);
    }
    
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        helper(matrix, 0, 0, matrix.size(), matrix[0].size(), res);
        
        return res;
    }
};