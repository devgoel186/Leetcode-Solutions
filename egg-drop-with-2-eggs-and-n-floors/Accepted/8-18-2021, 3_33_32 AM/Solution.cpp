// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors

class Solution {
public:
    int twoEggDrop(int n) {
        double x = sqrt(1 + 8 * n);
        x -= 1;
        x /= 2.0;
        return ceil(x);
    }
};