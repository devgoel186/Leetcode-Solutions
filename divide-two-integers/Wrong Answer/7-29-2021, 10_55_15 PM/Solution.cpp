// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        int x = abs(divisor), y = abs(dividend);
        if(x == 1)
        {
            if(dividend == INT_MIN && divisor == 1)
                return INT_MIN;
            else if(dividend == INT_MIN && divisor == -1)
                return INT_MAX;
            return dividend * divisor;
        }
        int count = 0;
        while(y >= x)
        {
            count++;
            y -= x;            
        }
        if((dividend < 0 || divisor < 0) && !(dividend < 0 && divisor < 0))
            return -1 * count;
        return count;
    }
};