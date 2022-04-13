// https://leetcode.com/problems/unique-paths

class Solution {
public:
    bool isSafe(int m, int n, int r, int c)
    {
        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;
        return true;
    }
    
    void helper(int m, int n, int r, int c, vector<vector<bool>> visited, int &count)
    {    
        if(!isSafe(m, n, r, c))
            return;
        
        if(r == m - 1 && c == n - 1)
        {
            count++;
            return;
        }
        
        if(visited[r][c])
            return;
        
        visited[r][c] = true;
        
        helper(m, n, r + 1, c, visited, count);
        helper(m, n, r, c + 1, visited, count);
        
        // visited[r][c] = false;
    }
    
    int uniquePaths(int m, int n) {
        int count = 0;
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        helper(m, n, 0, 0, visited, count);
        return count;
    }
};