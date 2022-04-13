// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void color(vector<vector<int>>& matrix, int x, int y)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            matrix[i][y] = 0;    
        }
        
        for(int j = 0; j < matrix[x].size(); j++)
        {
            matrix[x][j] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> store;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    store.push_back({i, j});
                }
            }
        }
        
        for(auto i : store)
        {
            color(matrix, i.first, i.second);
        }
    }
};