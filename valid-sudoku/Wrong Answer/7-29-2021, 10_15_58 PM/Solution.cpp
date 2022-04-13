// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == num)
                return false;
        }
        
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == num)
                return false;
        }
        
        int rowStart = row - row % 3;
        int colStart = col - col % 3;
        for(int i = rowStart; i < rowStart + 3; i++)
        {
            for(int j = colStart; j < colStart + 3; j++)
            {
                if(board[i][j] == num)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudokuHelper(vector<vector<char>>& board, int row, int col) {
        if(row == 8 && col == 9)
            return true;
        
        if(col == 9)
        {
            row++;
            col = 0;
        }
        
        if(board[row][col] != '.')
            return isValidSudokuHelper(board, row, col + 1);
        
        for(char i = 1 + '0'; i <= 9 + '0'; i++)
        {
            if(isSafe(board, row, col, i))
            {
                board[row][col] = i;
                if(isValidSudokuHelper(board, row, col + 1))
                    return true;
            }
            
            board[row][col] = '.';
        }
        
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudokuHelper(board, 0, 0);
    }
};