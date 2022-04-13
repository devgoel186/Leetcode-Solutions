// https://leetcode.com/problems/unique-paths

class Solution {
public:
    bool isSafe(int m, int n, int r, int c)
    {
        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;
        return true;
    }
    
    void helper(int m, int n, int r, int c, int &count)
    {
        if(r == m - 1 && c == n - 1)
        {
            count++;
            return;
        }
        
        if(!isSafe(m, n, r, c))
            return;
        
        helper(m, n, r + 1, c, count);
        helper(m, n, r, c + 1, count);
    }
    
    int uniquePaths(int m, int n) {
        int count = 0;
        helper(m, n, 0, 0, count);
        return count;
    }
};