// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        char sq = '0';
        
        if(matrix.size() == 0)
        {
            return 0;
        }
        else if(matrix[0].size() == 1)
        {
            return 0;
        }
                
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(i == 0 || j == 0)
                {
                    if(matrix[i][j] == '0')
                        continue;
                    // matrix[i][j] = 1;
                    sq = max(matrix[i][j], sq);
                }
                else
                {
                    if(matrix[i][j] == '0')
                        continue;
                    matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
                    sq = max(matrix[i][j], sq);
                }
            }
        }
        
        return pow((sq - '0'), 2);
    }
};