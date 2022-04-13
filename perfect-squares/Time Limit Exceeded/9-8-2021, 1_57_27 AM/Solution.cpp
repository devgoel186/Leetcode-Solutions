// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        if(sqrt(n) - floor(sqrt(n)) == 0)
            return 1;
            
        if(n <= 3)
            return n;
        
        int res = n;
        for(int i = 1; i * i <= n; i++)
            res = min(res, numSquares(n - i * i) + 1);
        
        return res;
    }
};