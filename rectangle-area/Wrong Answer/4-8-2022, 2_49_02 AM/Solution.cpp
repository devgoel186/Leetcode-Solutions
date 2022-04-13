// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);
        int c = 0;
        
        if((ax2 > bx1) && (by2 > ay1))
            c = (ax2 - max(bx1, ax1)) * (by2 - max(ay1, by1));
        
        return a + b - c;
    }
};