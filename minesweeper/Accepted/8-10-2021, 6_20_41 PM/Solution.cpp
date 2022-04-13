// https://leetcode.com/problems/minesweeper

class Solution {
public:
    bool isSafe(int r, int c, int row, int col)
    {
        if(r < 0 || r >= row || c < 0 || c >= col)
            return false;
        return true;
    }
    
    void handleCase(vector<vector<char>>& board, int r, int c)
    {
        if(!isSafe(r, c, board.size(), board[0].size()))
            return;
        
        vector<pair<int, int>> dir({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});

        int count = 0;
        for(int i = 0; i < 8; i++)
        {
            int x = r + dir[i].first, y = c + dir[i].second;
            
            if(!isSafe(x, y, board.size(), board[0].size()))
                continue;            
            
            if(board[x][y] == 'M' || board[x][y] == 'X')
                count++;
        }        
        
        board[r][c] = (count == 0) ? 'B' : '0' + count;
        
        if(count == 0)
        {
            for(int i = 0; i < 8; i++)
            {
                int x = r + dir[i].first, y = c + dir[i].second;
                
                if(!isSafe(x, y, board.size(), board[0].size()))
                    continue;

                if(board[x][y] == 'E')
                    handleCase(board, x, y);
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        
        if(board[r][c] == 'M')
            board[r][c] = 'X';
        
        else if(board[r][c] == 'E')
            handleCase(board, r, c);
        
        return board;
    }
};