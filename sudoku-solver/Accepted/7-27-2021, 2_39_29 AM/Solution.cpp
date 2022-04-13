// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char index)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == index)
                return false;
        }
        for(int j = 0; j < 9; j++)
        {
            if(board[row][j] == index)
                return false;
        }
        
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for(int i = startRow; i < startRow + 3; i++)
        {
            for(int j = startCol; j < startCol + 3; j++)
            {
                if(board[i][j] == index)
                    return false;
            }
        }
        return true;
    }
    
    bool solveSudokuHelper(vector<vector<char>>& board, int row, int col)
    {
        if(row == 8 && col == 9)
            return true;
        
        if(col == 9)
        {
            row++;
            col = 0;
        }
        
        if(board[row][col] != '.')
        {
            return solveSudokuHelper(board, row, col + 1);
        }
            
        for(char i = '1'; i <= '9'; i++)
        {
            if(isSafe(board, row, col, i))
            {
                board[row][col] = i;
                if(solveSudokuHelper(board, row, col + 1))
                    return true;
            }
            board[row][col] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudokuHelper(board, 0, 0);
    }
};