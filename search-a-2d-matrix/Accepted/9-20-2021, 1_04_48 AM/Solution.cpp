// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int r, int c, int m, int n)
    {
        if(r >= m || c < 0)
            return false;
        
        if(matrix[r][c] == target)
            return true;
        
        else if(matrix[r][c] < target)
            return helper(matrix, target, r + 1, c, m, n);
        
        return helper(matrix, target, r, c - 1, m, n);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return helper(matrix, target, 0, n - 1, m, n);
    }
};