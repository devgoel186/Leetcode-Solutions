// https://leetcode.com/problems/game-of-life

class Solution {
public:
    int sum(vector<vector<int>> &board, int i, int j)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return 0;
        return board[i][j];
    }
    
    int helper(vector<vector<int>> &board, int i, int j)
    {
        int count = sum(board, i - 1, j - 1) + sum(board, i - 1, j) + sum(board, i - 1, j + 1) + sum(board, i, j - 1) +
                           sum(board, i, j + 1) + sum(board, i + 1, j - 1) + sum(board, i + 1, j) + sum(board, i + 1, j + 1);
        
        cout << count << " ";
        
        if(board[i][j] == 1)
        {
            if(count < 2)
                return 0;
            else if(count >= 2 && count <= 3)
                return 1;
            else if(count > 3)
                return 0;
        }
        
        else
        {
            if(count == 3)
                return 1;
        }
        
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> newState(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                newState[i][j] = helper(board, i, j);
            }
        }
        
        board = newState;
    }
};