// https://leetcode.com/problems/flood-fill

class Solution {
public:
    bool isSafe(vector<vector<int>>& m, int r, int c, int og)
    {
        if(r < 0 || c < 0 || r >= m.size() || c >= m[0].size() || m[r][c] != og)
            return false;
        return true;
    }
    
    void fill(vector<vector<int>>& m, int r, int c, int og, int color)
    {
        if(!isSafe(m, r, c, og))
            return;
        
        m[r][c] = color;
        
        fill(m, r + 1, c, og, color);
        fill(m, r - 1, c, og, color);
        fill(m, r, c + 1, og, color);
        fill(m, r, c - 1, og, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)
            fill(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};