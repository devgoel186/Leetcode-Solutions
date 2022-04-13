// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int r, int c)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O')
            return false;
        return true;
    }
    
    void mark(vector<vector<char>> &board, int r, int c)
    {
        if(!isSafe(board, r, c))
            return;
        
        board[r][c] = '*';
        
        mark(board, r, c + 1);
        mark(board, r, c - 1);
        mark(board, r + 1, c);
        mark(board, r - 1, c);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                mark(board, i, 0);
            
            if(board[i][n - 1] == 'O')
                mark(board, i, n - 1);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
                mark(board, 0, i);
            
            if(board[m - 1][i] == 'O')
                mark(board, m - 1, i);
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};