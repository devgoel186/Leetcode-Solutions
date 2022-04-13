// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchUtil(vector<vector<int>> &matrix, int target, int r, int c)
    {
        int m = matrix.size(), n = matrix[0].size();
        if(r >= m || c < 0)
            return false;
        
        if(matrix[r][c] == target)
            return true;
        
        if(matrix[r][c] > target)
            return searchUtil(matrix, target, r, c - 1);
        
        return searchUtil(matrix, target, r + 1, c);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchUtil(matrix, target, 0, matrix[0].size() - 1);
    }
};