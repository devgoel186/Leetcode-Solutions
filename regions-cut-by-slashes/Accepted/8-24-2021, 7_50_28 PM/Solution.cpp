// https://leetcode.com/problems/regions-cut-by-slashes

class Solution {
public:
    bool isSafe(vector<vector<int>> &m, int r, int c)
    {
        if(r < 0 || c < 0 || r >= m.size() || c >= m.size() || m[r][c] != 0)
            return false;
        return true;
    }
    
    void detect(vector<vector<int>> &m, int r, int c)
    {
        if(!isSafe(m, r, c))
            return;
        
        m[r][c] = 2;
        
        detect(m, r + 1, c);
        detect(m, r - 1, c);
        detect(m, r, c + 1);
        detect(m, r, c - 1);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> m(3 * grid.size(), vector<int> (3 * grid.size(), 0));
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if(grid[i][j] == '/')
                    m[3 * i][3 * j + 2] = m[3 * i + 1][3 * j + 1] = m[3 * i + 2][3 * j] = 1;
                if(grid[i][j] == '\\')
                    m[3 * i][3 * j] = m[3 * i + 1][3 * j + 1] = m[3 * i + 2][3 * j + 2] = 1;
            }
        }
        
        int regions = 0;
        for(int i = 0; i < m.size(); i++)
        {
            for(int j = 0; j < m.size(); j++)
            {
                if(m[i][j] == 0)
                {
                    detect(m, i, j);
                    regions++;
                }
            }
        }
        
        return regions;
    }
};