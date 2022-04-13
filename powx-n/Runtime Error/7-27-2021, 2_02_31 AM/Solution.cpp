// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x; 
        if(n < 0)
            return myPow((1.0/x), -1 * n);
        return x * myPow(x, n - 1);
    }
};