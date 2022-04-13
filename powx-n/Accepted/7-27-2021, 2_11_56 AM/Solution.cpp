// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int temp = n;
        if(n == INT_MIN)
        {
            n = n + 1;
            n = -1 * n;
            ans = ans / x;
        }
        if(n < 0)
            n = -1 * n;
        while(n != 0)
        {
            if(n % 2 == 0)
            {
                x *= x;
                n /= 2;
            }
            else
            {
                ans = ans * x;
                n -= 1;
            }
        }
        if(temp < 0)
            return 1.0 / ans;
        return ans;
    }
};