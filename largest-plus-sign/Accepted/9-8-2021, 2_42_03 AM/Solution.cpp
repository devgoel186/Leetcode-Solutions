// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n, 501));
        
        for(auto i : mines)
        {
            grid[i[0]][i[1]] = 0;
        }
        
        for(int i = 0; i < n; i++)
        {
            int l = 0;
            
            for(int j = 0; j < n; j++)
            {
                int temp = grid[i][j];
                if(temp != 0)
                    l++;
                else
                    l = 0;
                grid[i][j] = min(temp, l);
            }
            
            l = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                int temp = grid[i][j];
                if(temp != 0)
                    l++;
                else
                    l = 0;
                grid[i][j] = min(temp, l);
            }
            
            l = 0;
            for(int j = 0; j < n; j++)
            {
                int temp = grid[j][i];
                if(temp != 0)
                    l++;
                else
                    l = 0;
                grid[j][i] = min(temp, l);
            }
            
            l = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                int temp = grid[j][i];
                if(temp != 0)
                    l++;
                else
                    l = 0;
                grid[j][i] = min(temp, l);
            }
        }
        
        int maxPlus = 0;
        for(auto i : grid)
            for(auto j : i)
                maxPlus = max(maxPlus, j);
        
        return maxPlus;
    }
};