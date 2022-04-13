// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char x)
    {
        if(r < 0 || c < 0 || r >= 9 || c >= 9)
            return false;
        
        for(int i = 0; i < 9; i++)
        {
            if(board[i][c] == x)
                return false;
        }
        
        for(int i = 0; i < 9; i++)
        {
            if(board[r][i] == x)
                return false;
        }
        
        int rowStart = r - r % 3;
        int colStart = c - c % 3;
        
        for(int i = rowStart; i < rowStart + 3; i++)
        {
            for(int j = colStart; j < colStart + 3; j++)
            {
                if(board[i][j] == x)
                    return false;
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board, int r, int c)
    {   
        if(r == 8 && c == 9)
            return true;
        
        if(c == 9)
        {
            c = 0;
            r++;
        }
        
        if(board[r][c] != '.')
            return helper(board, r, c + 1);
        
        for(char i = '1'; i <= '9'; i++)
        {
            if(isSafe(board, r, c, i))
            {
                board[r][c] = i;
                if(helper(board, r, c + 1))
                    return true;
                board[r][c] = '.';
            }
        }
        
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board)
    {
        helper(board, 0, 0);
    }
};