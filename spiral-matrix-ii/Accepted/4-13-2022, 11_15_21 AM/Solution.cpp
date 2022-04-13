// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
    private:
    bool check(int a, int b, int m, int n)
    {
        if(a >= m || b >= n)
            return true;
        return false;
    }
    
    void helper(vector<vector<int>> &matrix, int a, int b, int m, int n, int &count)
    {
        if(check(a, b, m, n))
            return;
        
        if(count == matrix.size() * matrix.size() + 1)
            return;
        
        for(int i = b; i < n; i++)
        {
            matrix[a][i] = count;
            count++;
        }
        a++;
        if(check(a, b, m, n))
            return;
        
        for(int i = a; i < m; i++)
        {
            matrix[i][n - 1] = count;
            count++;
        }
        n--;
        if(check(a, b, m, n))
            return;
        
        for(int i = n - 1; i >= b; i--)
        {
            matrix[m - 1][i] = count;
            count++;
        }
        m--;
        if(check(a, b, m, n))
            return;
        
        for(int i = m - 1; i >= a; i--)
        {
            matrix[i][b] = count;
            count++;
        }
        b++;
        if(check(a, b, m, n))
            return;
        
        helper(matrix, a, b, m, n, count);
    }
    
    public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int count = 1;
        
        helper(matrix, 0, 0, n, n, count);
        return matrix;
    }
};