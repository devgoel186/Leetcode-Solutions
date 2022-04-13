// https://leetcode.com/problems/check-if-move-is-legal

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int m = board.size(), n = board[0].size();
        
        bool flag = false;
        
        if(cMove + 1 < n && board[rMove][cMove + 1] != color)
        {
            for(int j = cMove + 2; j < n; j++)
            {
                if(board[rMove][j] == '.')
                    break;
                
                if(board[rMove][j] == color)
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if(cMove - 1 >= 0 && board[rMove][cMove - 1] != color)
        {
            for(int j = cMove - 2; j >= 0; j--)
            {
                if(board[rMove][j] == '.')
                    break;
                
                if(board[rMove][j] == color)
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if(rMove + 1 < m && board[rMove + 1][cMove] != color)
        {
            for(int i = rMove + 2; i < m; i++)
            {
                if(board[i][cMove] == '.')
                    break;
                
                if(board[i][cMove] == color)
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if(rMove - 1 >= 0 && board[rMove - 1][cMove] != color)
        {
            for(int i = rMove - 2; i >= 0; i--)
            {
                if(board[i][cMove] == '.')
                    break;
                
                if(board[i][cMove] == color)
                {
                    flag = true;
                    break;
                }
            }
        }
        
        
        // Diagonal search
        if(cMove + 1 < n && rMove + 1 < m && board[rMove + 1][cMove + 1] != color)
        {
            int i = rMove + 2, j = cMove + 2;
            while(i < m && j < n)
            {
                if(board[i][j] == '.')
                    break;
                
                if(board[i][j] == color)
                {
                    flag = true;
                    break;
                }
                i++;
                j++;
            }
        }
        
        if(cMove - 1 < n && rMove - 1 < m && board[rMove - 1][cMove - 1] != color)
        {
            int i = rMove - 2, j = cMove - 2;
            while(i >= 0 && j >= 0)
            {
                if(board[i][j] == '.')
                    break;
                
                if(board[i][j] == color)
                {
                    flag = true;
                    break;
                }
                i--;
                j--;
            }
        }
        
        if(cMove + 1 < n && rMove - 1 < m && board[rMove - 1][cMove + 1] != color)
        {
            int i = rMove - 2, j = cMove + 2;
            while(i >= 0 && j < n)
            {
                if(board[i][j] == '.')
                    break;
                
                if(board[i][j] == color)
                {
                    flag = true;
                    break;
                }
                i--;
                j++;
            }
        }
        
        if(cMove - 1 < n && rMove + 1 < m && board[rMove + 1][cMove - 1] != color)
        {
            int i = rMove + 2, j = cMove - 2;
            while(i < m && j >= 9)
            {
                if(board[i][j] == '.')
                    break;
                
                if(board[i][j] == color)
                {
                    flag = true;
                    break;
                }
                i++;
                j--;
            }
        }
        
        return flag;
    }
};