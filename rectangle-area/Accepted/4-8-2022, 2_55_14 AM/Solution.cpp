// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);        
        
        int l = max(ax1, bx1);
        int r = max(l, min(ax2, bx2));
        
        int d = max(ay1, by1);
        int t = max(d, min(ay2, by2));
        
        int c = (r - l) * (t - d);
        
        return a + b - c;
    }
};