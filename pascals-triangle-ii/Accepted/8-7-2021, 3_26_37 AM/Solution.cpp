// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> res(numRows + 1);
        
        for(int i = 0; i <= numRows; i++)
        {
            res[i] = vector<int>(i + 1);
        }
        
        res[0] = {1};
        
        if(numRows == 0)
            return res[0];
        
        res[1] = {1, 1};
        
        for(int i = 2; i <= numRows; i++)
        {
            res[i][0] = 1;
            for(int j = 1; j <= (i + 1) / 2; j++)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                res[i][i - j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res[i][i] = 1;
        }
        
        return res[numRows];
    }
};