// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1)
            return x; 
        return x * myPow(x, n - 1);
    }
};