// https://leetcode.com/problems/word-search

class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int r, int c)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return false;
        return true;
    }
    
    bool util(vector<vector<char>> &board, string &word, int r, int c)
    {
        if(word.size() == 0)
            return true;
        
        if(!isSafe(board, r, c) || word[0] != board[r][c])
            return false;
        
        char ch = board[r][c];
        board[r][c] = '*';
        string res = word.substr(1);
        
        bool c1 = util(board, res, r + 1, c);
        bool c2 = util(board, res, r - 1, c);
        bool c3 = util(board, res, r, c + 1);
        bool c4 = util(board, res, r, c - 1);
        
        bool ans = c1 || c2 || c3 || c4;
        board[r][c] = ch;
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(util(board, word, i, j))
                    return true;
            }
        }
        
        return false;
    }
};